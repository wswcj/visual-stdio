#include<iostream>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int* p = NULL;
void init() {//屏幕初始化为白色
	for (int i = 0; i < 480; ++i) {
		for (int j = 0; j < 800; ++j) {
			*(p + j + i * 800) = 0x00FFFFFF;
		}
	}
}
void printCycle(int x, int y, int r, int color) {//打印圆形
	for (int i = 0; i < 480; ++i) {
		for (int j = 0; j < 800; ++j) {
			if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
				*(p + j + i * 800) = color;
			}
		}
	}
}
void printCycle1(int x1, int y1, int x2, int y2, int r, int color) {
	for (int i = 0; i < 480; ++i) {
		for (int j = 0; j < 800; ++j) {
			if ((i - x1) * (i - x1) + (j - y1) * (j - y1) <= r * r && (i - x2) * (i - x2) + (j - y2) * (j - y2) <= r * r) {
				*(p + j + i * 800) = color;
			}
		}
	}
}
void darw_point(int select, int color) {
	init();
	if (select == 1) {//打印矩形
		for (int i = 80; i < 400; ++i) {
			for (int j = 200; j < 600; ++j) {
				*(p + j + i * 800) = color;
			}
		}
	}
	if (select == 2) {//打印等边三角形
		for (int i = 80; i < 400; ++i) {
			for (int j = 200; j <= 120 + i; ++j) {
				*(p + j + i * 800) = color;
			}
		}
	}
	if (select == 3) {//打印圆形
		int x = 200, y = 400;//圆心
		int r = 100;//半径
		printCycle(x, y, r, color);
	}
	if (select == 4) {//打印四叶草1
		int r = 50;
		int x1 = 200, y1 = 350;//左
		int x2 = 200, y2 = 450;//右
		int x3 = 150, y3 = 400;//上
		int x4 = 250, y4 = 400;//下
		printCycle(x1, y1, r, color);
		printCycle(x2, y2, r, color);
		printCycle(x3, y3, r, color);
		printCycle(x4, y4, r, color);
	}
	if (select == 5) {//打印四叶草2
		int r = 50;
		int x1 = 200, y1 = 350;
		int x2 = 200, y2 = 450;
		int x3 = 150, y3 = 400;
		int x4 = 250, y4 = 400;
		printCycle1(x1, y1, x3, y3, r, color);
		printCycle1(x1, y1, x4, y4, r, color);
		printCycle1(x2, y2, x3, y3, r, color);
		printCycle1(x2, y2, x4, y4, r, color);
	}
}
int main() {
	cin.unsetf(ios::dec);
	cin.setf(ios::hex);
	int fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		cout << "打开失败!!! " << endl;
	}
	int buf[480][800];
	p = (int*)mmap(NULL, sizeof(buf), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	int select = 1;
	int color = 0;
	while (select) {

		cout << "请输入选择: ";
		cin >> select;
		cout << "请输入颜色: ";
		cin >> color;
		darw_point(select, color);
	}
	int m = munmap(p, sizeof(buf));
	if (m == -1) {
		cout << "解除失败!!!" << endl;
	}
	int c = close(fd);
	if (c == -1) {
		cout << "关闭失败!!!!" << endl;
	}
	return 0;
}