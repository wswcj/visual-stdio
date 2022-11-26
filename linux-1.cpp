#include<iostream>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main() {
	int fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		cout << "打开失败!!! " << endl;
	}
	int buf[480][800];
	int* p = (int*)mmap(NULL, sizeof(buf), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED) {
		cout << "映射失败!!!" << endl;
	}
	for (int i = 0; i < 480; ++i) {
		for (int j = 0; j < 800; ++j) {
			*(p + j + i * 800) = 0x00FF0000;
		}
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