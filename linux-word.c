#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>


int* p = NULL;

/*16x16*/ //保存了字的轮廓 模
unsigned char word[1][32] = { {0x20,0x00,0x3E,0x7C,0x48,0x44,0x08,0x44,0xFF,0x44,0x14,0x44,0x22,0x7C,0x40,0x00,
0x1F,0xF0,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10} };

void draw_point(int x, int y, int color)
{
	if (x >=0 && x < 800 && y >= 0 && y < 480)
		*(p + y * 800 + x) = color;

}

int main()
{
	//1.打开帧缓冲设备文件
	int lcd_fd = open("/dev/fb0", O_RDWR);
	if (lcd_fd < 0)
	{
		printf("open lcd_fd failed\n");
	}
	//2.映射
	p = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
	if (p == MAP_FAILED)
	{
		printf("mmap failed\n");
	}

	//刷底色->白色
	int i, j;
	for (i = 0; i < 480; i++)
	{
		for (j = 0; j < 800; j++)
		{
			draw_point(j, i, 0x00FFFFFF);
		}
	}


	//3.显示字 
	int num = 0;
	int x, y;
	for (i = 0; i < 32; i++)  //字节数
	{
		for (j = 7; j >= 0; j--) //每个字节8bit
		{
			if (word[0][i] & (1 << j))   // 1 << 7 -> 1000 0000 刷一个与底色不同的颜色
			{
				x = num % 16;   //x = (i % 2) * 8 + (7 -j); 
				y = num / 16;  //y = i / 2;
				draw_point(x, y, 0x00FF0000);
			}
			num++;
		}
	}

	//解除映射
	int c = munmap(p, 800 * 480 * 4);
	if (c == -1)
	{
		printf("munmap failed\n");
	}
	//关闭文件
	c = close(lcd_fd);
	if (c == -1)
	{
		printf("close lcd_fd failed\n");
	}



	return 0;
}