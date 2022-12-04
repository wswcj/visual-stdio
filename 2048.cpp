#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#define N 4
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE 
using namespace std;

class Game {
public:
	int board[N][N]{ 0 };         //定义棋盘的大小
	void setchessboard();              // 定义初始棋盘 
	void printchessboard();            //打印棋盘

	void up();                        // 四步操作
	void down();
	void left();
	void right();

	int score();                      //  记录分数
	int ifgameover();                 // 判断游戏结束
};

//  board[a][b] 中[a]控制的是行 [b]控制的是列

//以下代码中，定义c的作用相当于一个标尺（或者说参照物？）

void Game::up() {         //向上合并的话，第一行不用向上合并。采用的思路是一行一行来看 对上一行进行怎样的一步操作。  
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

void Game::down() { // 向下合并，最后一行不需要向下进行合并， 此处的思路为一行一行判断，看是否对下一行进行操作
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

void Game::left() { // 向左合并的话，第一列不用合并。采用的思路是一列一列看，看怎么样对上一列进行操作
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

void Game::right() { // 向右合并的话 ，最后一列不用合并，思路是一列一列看 ， 看怎样对下一列进行操作
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

void Game::setchessboard() {               // 初始棋盘生成
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

void Game::printchessboard() {   // 棋盘的打印实现
	cout << "————————————" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "|" << setw(4) << board[i][j] << "|";
		}
		cout << endl;
		cout << "————————————" << endl;
	}
}


int Game::score() {
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

int Game::ifgameover() {//判断游戏是否结束
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

int main()
{

	cout << "    by Fang Hanfei  " << endl;

	Game game;
	game.setchessboard();
	game.printchessboard();

	while (char ch = _getch()) {
		int b = game.ifgameover();
		int c = game.score();
		switch (ch) {
		case 75:
			game.left();  // 调用函数 void Game::left()
			switch (b) {
			case 0:
				system("CLS");//清屏
				cout << "你输了 !" << endl << "你的积分是： " << c << endl;  break;
			case 1:
				system("CLS");
				cout << "小伙子你真棒，居然赢了！" << endl; break;
			case 2:
				system("CLS");
				game.printchessboard(); break;
			}
			break;
		case 72:
			game.up(); // 调用函数void Game::up()
			switch (b) {
			case 0:
				system("CLS");
				cout << "你输了 !" << endl << "你的积分是： " << c << endl;  break;
			case 1:
				system("CLS");
				cout << "小伙子你真棒，居然赢了！" << endl; break;
			case 2:
				system("CLS");
				game.printchessboard(); break;
			}
			break;
		case 80:
			game.down(); // 调用函数void Game::down()
			switch (b) {
			case 0:
				system("CLS");
				cout << "你输了 !" << endl << "你的积分是： " << c << endl;  break;
			case 1:
				system("CLS");
				cout << "小伙子你真棒，居然赢了！" << endl; break;
			case 2:
				system("CLS");
				game.printchessboard(); break;
			}
			break;
		case 77:
			game.right(); // 调用函数void Game::right()
			switch (b) {
			case 0:
				system("CLS");
				cout << "你输了 !" << endl << "你的积分是： " << c << endl;  break;
			case 1:
				system("CLS");
				cout << "小伙子你真棒，居然赢了！" << endl; break;
			case 2:
				system("CLS");
				game.printchessboard(); break;
			}
			break;
		}
	}
	return 0;
}
