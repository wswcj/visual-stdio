#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

int* p = NULL;
void draw_point(int x, int y, int color)
{
	if (x >= 0 && x < 800 && y >= 0 && y < 480)
	{
		*(p + 800 * y + x) = color;
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


int main()
{
	//1.打开帧缓冲设备文件 
	int lcd_fd = open("/dev/fb0", O_RDWR);
	if (lcd_fd < 0)
	{
		cout << "Open failed" << endl;
	}
	//2.映射
	p = (int*)mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
	if (p == MAP_FAILED)
	{
		cout << "Mmap failed" << endl;
	}
	//显示图片
	show_bmp((char*)"3.bmp");
	sleep(5);
	show_bmp((char*)"2.bmp");
	sleep(5);
	show_bmp((char*)"1.bmp");
	//6.解除映射
	int c = munmap(p, 800 * 480 * 4);
	if (c == -1)
	{
		cout << "Munmap failed" << endl;
	}
	//7.关闭帧缓冲设备文件
	c = close(lcd_fd);
	if (c == -1)
	{
		cout << "Close failed" << endl;
	}

	return 0;
}