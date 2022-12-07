#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<linux/input.h>
#include <sys/mman.h>
#include<cstdlib>
#include <iomanip>

using namespace std;


#define N 4
int board[4][4] = { 0 };//棋盘大小
int* p = NULL;

bool flag = 0;   //用户是否移动

void draw_point(int x, int y, int color)
{
	if (x >= 0 && x < 800 && y >= 0 && y < 480)
	{
		*(p + 800 * y + x) = color;
	}
}



void show_numbmp(char* pathname, int x, int y)
{
	//3.打开图片文件
	int picture_fd = open(pathname, O_RDWR);
	if (picture_fd < 0)
	{
		cout << "Open failed" << endl;
	}
	//4.读取颜色值 写入帧缓冲设备文件
	//略过文件的头
	unsigned char head[54] = { 0 };
	int ret = read(picture_fd, head, 54);
	if (ret == -1)
	{
		cout << "read picture_fd's head failed" << endl;
	}
	//读取颜色值 
	unsigned char buf[800 * 480 * 3] = { 0 };
	ret = read(picture_fd, buf, 100 * 100 * 3);
	if (ret == -1)
	{
		cout << "read picture_fd's colorvalue failed" << endl;
	}
	unsigned char a = 0;  //透明度 
	int i, j;
	int num = 0;
	for (i = 0; i < 100; i++)  //行
	{
		for (j = 0; j < 100; j++)//列
		{
			int color = a << 24 | buf[num + 2] << 16 | buf[num + 1] << 8 | buf[num + 0];
			draw_point(x + j, y + 99 - i, color);  //写入帧缓冲设备文件
			num = num + 3;
		}
	}

	//5.关闭图片文件
	int c = close(picture_fd);
	if (c == -1)
	{
		cout << "Close failed" << endl;
	}
}


void show_bmp(char* pathname)
{
	//3.打开图片文件
	int picture_fd = open(pathname, O_RDWR);
	if (picture_fd < 0)
	{
		cout << "Open failed" << endl;
	}
	//4.读取颜色值 写入帧缓冲设备文件
	//略过文件的头
	unsigned char head[54] = { 0 };
	int ret = read(picture_fd, head, 54);
	if (ret == -1)
	{
		cout << "Read failed" << endl;
	}
	//读取颜色值 
	unsigned char buf[800 * 480 * 3] = { 0 };
	ret = read(picture_fd, buf, 800 * 480 * 3);
	if (ret == -1)
	{
		cout << "Read failed" << endl;
	}
	unsigned char a = 0;  //透明度 
	int i, j;
	int num = 0;
	for (i = 0; i < 480; i++)  //行
	{
		for (j = 0; j < 800; j++)//列
		{
			int color = a << 24 | buf[num + 2] << 16 | buf[num + 1] << 8 | buf[num + 0];
			draw_point(j, 479 - i, color);  //写入帧缓冲设备文件
			num = num + 3;
		}
	}

	//5.关闭图片文件
	int c = close(picture_fd);
	if (c == -1)
	{
		cout << "Close failed" << endl;
	}
}


//根据数组的值以及位置显示界面
void show_ui()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{	//0 2 4 8 16 32 ... 2048			
			switch (board[i][j])
			{
			case  0:show_numbmp((char*)"./0.bmp", i * 100 + 200, j * 100 + 40); break;
			case  2:show_numbmp((char*)"./2.bmp", i * 100 + 200, j * 100 + 40); break;
			case  4:show_numbmp((char*)"./4.bmp", i * 100 + 200, j * 100 + 40); break;
			case  8:show_numbmp((char*)"./8.bmp", i * 100 + 200, j * 100 + 40); break;
			case  16:show_numbmp((char*)"./16.bmp", i * 100 + 200, j * 100 + 40); break;
			case  32:show_numbmp((char*)"./32.bmp", i * 100 + 200, j * 100 + 40); break;
			case  64:show_numbmp((char*)"./64.bmp", i * 100 + 200, j * 100 + 40); break;
			case  128:show_numbmp((char*)"./128.bmp", i * 100 + 200, j * 100 + 40); break;
			case  256:show_numbmp((char*)"./256.bmp", i * 100 + 200, j * 100 + 40); break;
			case  512:show_numbmp((char*)"./512.bmp", i * 100 + 200, j * 100 + 40); break;
			case  1024:show_numbmp((char*)"./1024.bmp", i * 100 + 200, j * 100 + 40); break;
			case  2048:show_numbmp((char*)"./2048.bmp", i * 100 + 200, j * 100 + 40); break;
			default: break;
			}

		}
	}
}



void setchessboard() {               // 初始棋盘生成
	srand((unsigned)time(NULL));
	int x, y, a, b;
	int z = 0;
	x = rand() % N;
	y = rand() % N;
	board[x][y] = 2;
	do {
		a = rand() % N;
		b = rand() % N;
	} while (a == x && b == y);
	board[a][b] = 2;
}



void up() {         //向上合并的话，第一行不用向上合并。采用的思路是一行一行来看 对上一行进行怎样的一步操作。  
	int h = 0;
	for (int a = 1; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (board[a][b] != 0 && board[a - 1][b] == 0) {
				h = 1; break;
			}
			if (board[a - 1][b] == board[a][b] && board[a - 1][b] != 0) {
				h = 1; break;
			}
		}
	}

	for (int c = 0; c < N - 1; c++) { // 此处 由于a = c + 1时，最后一行已经判断，故 c < N - 1
		for (int a = c + 1; a > 0; a--) {//从 c 的下一行开始往上扫过一遍
			for (int b = 0; b < N; b++) {
				if (board[a - 1][b] == 0) {// 第a行的上一行情况
					board[a - 1][b] = board[a][b];
					board[a][b] = 0;// 从上往下进行值的“交换”
				}
			}
		}
	}

	for (int a = 1; a < N; a++) {
		for (int b = 0; b < N; b++) {
			board[a - 1][b] == board[a][b] ? board[a - 1][b] *= 2, board[a][b] = 0 : board[a][b] = board[a][b]; // 冒号后面的部分无意义
		}
	}

	for (int c = 0; c < N - 1; c++) { // 此处 由于a = c + 1时，最后一行已经判断，故 c < N - 1
		for (int a = c + 1; a > 0; a--) {//从 c 的下一行开始往上扫过一遍
			for (int b = 0; b < N; b++) {
				if (board[a - 1][b] == 0) {// 第a行的上一行情况
					board[a - 1][b] = board[a][b];
					board[a][b] = 0;// 从上往下进行值的“交换”
				}
			}
		}
	}

	if (h) {
		srand((unsigned)time(NULL));
		int x, y;
		do {
			x = rand() % N;
			y = rand() % N;
		} while (board[x][y] != 0);
		int c = rand() % 4 + 1;
		switch (c) {
		case 1:
		case 2:
		case 3:  board[x][y] = 2, h = 0; break;
		default: board[x][y] = 4, h = 0; break;
		}
	}
}

void down() { // 向下合并，最后一行不需要向下进行合并， 此处的思路为一行一行判断，看是否对下一行进行操作
	int h = 0;
	for (int a = N - 2; a >= 0; a--) {
		for (int b = 0; b < N; b++) {
			if (board[a][b] != 0 && board[a + 1][b] == 0) {
				h = 1; break;
			}
			if (board[a + 1][b] == board[a][b] && board[a + 1][b] != 0) {
				h = 1; break;
			}
		}
	}

	for (int c = N - 1; c > 0; c--) {
		for (int a = c - 1; a < N; a++) {  // 从 c 的上一行开始往上扫
			for (int b = 0; b < N; b++) {
				if (board[a + 1][b] == 0) {   // 第a行的下一行的情况
					board[a + 1][b] = board[a][b];
					board[a][b] = 0;
				}
			}
		}
	}

	for (int a = N - 2; a >= 0; a--) {
		for (int b = 0; b < N; b++) {
			board[a + 1][b] == board[a][b] ? board[a + 1][b] *= 2, board[a][b] = 0 : board[a][b] = board[a][b];
		}
	}

	for (int c = N - 1; c > 0; c--) {
		for (int a = c - 1; a < N; a++) {  // 从 c 的上一行开始往上扫
			for (int b = 0; b < N; b++) {
				if (board[a + 1][b] == 0) {   // 第a行的下一行的情况						board[a + 1][b] = board[a][b];
					board[a][b] = 0;
				}
			}
		}
	}

	if (h) {
		srand((unsigned)time(NULL));
		int x, y;
		do {
			x = rand() % N;
			y = rand() % N;
		} while (board[x][y] != 0);
		int c = rand() % 4 + 1;
		switch (c) {
		case 1:
		case 2:
		case 3:  board[x][y] = 2, h = 0; break;
		default: board[x][y] = 4, h = 0; break;
		}
	}
}

void left() { // 向左合并的话，第一列不用合并。采用的思路是一列一列看，看怎么样对上一列进行操作
	int h = 0;
	for (int b = 1; b < N; b++) {
		for (int a = 0; a < N; a++) {
			if (board[a][b] != 0 && board[a][b - 1] == 0) {
				h = 1; break;
			}
			if (board[a][b - 1] == board[a][b] && board[a][b] != 0) {
				h = 1; break;
			}
		}
	}
	for (int c = 0; c < N - 1; c++) {
		for (int b = c + 1; b > 0; b--) { // 从第c列的右边开始往左扫
			for (int a = 0; a < N; a++) {// 从最后一行开始判断
				if (board[a][b - 1] == 0) {// 第b列的左一列
					board[a][b - 1] = board[a][b];
					board[a][b] = 0;
				}
			}
		}
	}

	for (int b = 1; b < N; b++) {
		for (int a = 0; a < N; a++) {
			board[a][b - 1] == board[a][b] ? board[a][b - 1] *= 2, board[a][b] = 0 : board[a][b - 1] = board[a][b - 1];
		}
	}

	for (int c = 0; c < N - 1; c++) {
		for (int b = c + 1; b > 0; b--) { // 从第c列的右边开始往左扫
			for (int a = 0; a < N; a++) {// 从最后一行开始判断
				if (board[a][b - 1] == 0) {// 第b列的左一列
					board[a][b - 1] = board[a][b];
					board[a][b] = 0;
				}
			}
		}
	}

	if (h) {
		srand((unsigned)time(NULL));
		int x, y;
		do {
			x = rand() % N;
			y = rand() % N;
		} while (board[x][y] != 0);
		int c = rand() % 4 + 1;
		switch (c) {
		case 1:
		case 2:
		case 3:  board[x][y] = 2, h = 0; break;
		default: board[x][y] = 4, h = 0; break;
		}
	}
}

void right() { // 向右合并的话 ，最后一列不用合并，思路是一列一列看 ， 看怎样对下一列进行操作
	int h = 0;
	for (int b = N - 2; b >= 0; b--) {
		for (int a = 0; a < N; a++) {
			if (board[a][b] != 0 && board[a][b + 1] == 0) {
				h = 1; break;
			}
			if (board[a][b + 1] == board[a][b] && board[a][b] != 0) {
				h = 1; break;
			}
		}
	}

	for (int c = N - 1; c > 0; c--) {
		for (int b = c - 1; b < N - 1; b++) { //从第c列的左边开始往右扫
			for (int a = 0; a < N; a++) {
				if (board[a][b + 1] == 0) {//第b列的右一列
					board[a][b + 1] = board[a][b];
					board[a][b] = 0;
				}
			}
		}
	}

	for (int b = N - 2; b >= 0; b--) { //从第c列的左边开始往右扫
		for (int a = 0; a < N; a++) {
			board[a][b + 1] == board[a][b] ? board[a][b + 1] *= 2, board[a][b] = 0 : board[a][b] = board[a][b];
		}
	}

	for (int c = N - 1; c > 0; c--) {
		for (int b = c - 1; b < N - 1; b++) { //从第c列的左边开始往右扫
			for (int a = 0; a < N; a++) {
				if (board[a][b + 1] == 0) {//第b列的右一列
					board[a][b + 1] = board[a][b];
					board[a][b] = 0;
				}
			}
		}
	}

	if (h) {
		srand((unsigned)time(NULL));
		int x, y;
		do {
			x = rand() % N;
			y = rand() % N;
		} while (board[x][y] != 0);
		int c = rand() % 4 + 1;
		switch (c) {
		case 1:
		case 2:
		case 3:  board[x][y] = 2, h = 0; break;
		default: board[x][y] = 4, h = 0; break;
		}
	}
}


int score() {
	int c = 0;
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			c += board[a][b];
		}
	}
	return c;
}

int ifgameover() {//判断游戏是否结束
	int c = 0;      // case 0 ： 输了，算积分

	for (int a = 0; a < N; a++) {
		if (c == 1) break;
		for (int b = 0; b < N; b++) {
			if (board[a][b] == 2048) {//  case 1: 赢了
				c = 1;
				break;
			}
		}
	}

	for (int a = 0; a < N; a++) {//检查相邻两列
		if (c == 1) break;
		if (c != 1) {
			for (int b = 0; b < N - 1; b++) {
				if (board[a][b] == 0 || board[a][b] == board[a][b + 1]) {
					c = 2;  //  case 2 : 继续游戏
					break;
				}
			}
		}
	}

	for (int b = 0; b < N; b++) {// 检查相邻两行
		if (c == 1) break;
		if (c != 1) {
			for (int a = 0; a < N - 1; a++) {
				if (board[a][b] == 0 || board[a][b] == board[a + 1][b]) {
					c = 2;
					break;
				}
			}
		}
	}
	return c;
}

int main() {
	int fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		cout << "打开失败!!! " << endl;
	}


	p = (int*)mmap(NULL, 480 * 800 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED) {
		cout << "映射失败!!!" << endl;
	}
	

	setchessboard();  // 初始棋盘生成

	show_ui();

	int fd1 = open("/dev/input/event0", O_RDWR);
	if (fd1 < 0) {
		cout << "Open failed" << endl;
	}

	int x, y, x_start, y_start, x_stop, y_stop;
	struct input_event ev;
	bool over = 0;
	while (1)
	{
		int b = ifgameover(); //0 , 1 , 2
		int c = score();

		int ret = read(fd1, &ev, sizeof(ev));
		if (ret == -1)
		{
			cout << "Read failed" << endl;
			continue;
		}

		if (ev.type == EV_ABS && ev.code == ABS_X)  //x事件
		{
			x = ev.value;
		}
		else if (ev.type == EV_ABS && ev.code == ABS_Y)  //y事件
		{
			y = ev.value;
		}
		else if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 1) //点击事件 表示是按下去了
		{
			x_start = x;
			y_start = y;
		}
		else if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0) //表示弹起来了
		{
			x_stop = x;
			y_stop = y;

			if (abs(x_stop - x_start) > abs(y_stop - y_start) && abs(x_stop - x_start) > 50)  //X方向的事件
			{
				if (x_stop - x_start > 0)  //右滑
				{
					down();
					switch (b) {
					case 0:
						over = 1;
						show_bmp((char*)"game_over.bmp");
						cout << "你输了 !" << endl << "你的积分是： " << c << endl;
						break;
					case 1:
						over = 1;
						show_bmp((char*)"win.bmp");
						cout << "小伙子你真棒，居然赢了！" << endl;
						break;
					case 2:

						show_ui(); break;
					}
				}
				else  					//左滑
				{
					up();
					switch (b) {
					case 0:
						over = 1;
						show_bmp((char*)"game_over.bmp");
						cout << "你输了 !" << endl << "你的积分是： " << c << endl;
						break;
					case 1:
						over = 1;
						show_bmp((char*)"win.bmp");
						cout << "小伙子你真棒，居然赢了！" << endl;
						break;
					case 2:

						show_ui(); break;
					}
				}
			}
			else if (abs(x_stop - x_start) < abs(y_stop - y_start) && abs(y_stop - y_start) > 50)  //Y方向的事件
			{
				if (y_stop - y_start > 0)  //下滑
				{
					right();
					switch (b) {
					case 0:
						over = 1;
						show_bmp((char*)"game_over.bmp");
						cout << "你输了 !" << endl << "你的积分是： " << c << endl;
						break;
					case 1:
						over = 1;
						show_bmp((char*)"win.bmp");
						cout << "小伙子你真棒，居然赢了！" << endl;
						break;
					case 2:

						show_ui(); break;
					}
				}
				else  					//上滑
				{
					left();
					switch (b) {
					case 0:
						over = 1;
						show_bmp((char*)"game_over.bmp"); 
						cout << "你输了 !" << endl << "你的积分是： " << c << endl; 
						break;
					case 1:
						over = 1;
						show_bmp((char*)"win.bmp"); 
						cout << "小伙子你真棒，居然赢了！" << endl;
						break;
					case 2:

						show_ui(); break;
					}
				}
			}

			else //点击  
			{
				
			}
			if (over == 1) {
				break;
			}
		}

	}


	int m = munmap(p, 480 * 800 * 4);
	if (m == -1) {
		cout << "解除失败!!!" << endl;
	}
	int c = close(fd);
	if (c == -1) {
		cout << "关闭失败!!!!" << endl;
	}
	return 0;
}