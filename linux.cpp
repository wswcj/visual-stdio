#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main() {
	int fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		cout << "打开失败!!!" << endl;
	}
	int buf[480][800] = { 0 };
	for (int i = 0; i < 480; ++i) {
		for (int j = 0; j < 800; ++j) {
			buf[i][j] = 0x00FF0000;
		}
	}
	for (int i = 180; i < 220; ++i) {
		for (int j = 200; j < 400; ++j) {
			buf[i][j] = 0x0000FF00;
		}
	}
	for (int i = 280; i < 340; ++i) {
		for (int j = 100; j < 500; ++j) {
			buf[i][j] = 0x0000FF00;
		}
	}
	for (int i = 80; i < 420; ++i) {
		for (int j = 380; j < 420; ++j) {
			buf[i][j] = 0x0000FF00;
		}
	}
	size_t count = sizeof(buf);
	int r = write(fd, buf, count);
	if (r == -1) {
		cout << "写入失败!!!" << endl;
	}
	int c = close(fd);
	if (c == -1) {
		cout << "关闭失败!!!" << endl;
	}
	return 0;
}