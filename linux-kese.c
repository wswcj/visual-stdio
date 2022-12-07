//////////////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2017, GEC Tech. Co., Ltd.
//
//  File name: GPLE/voicectl.c
//
//  Author: GEC
//
//  Date: 2017-01
//  
//  Description: 获取语音指令，根据指令完成相应动作
//
//
//////////////////////////////////////////////////////////////////

#include "common.h"
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<linux/input.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#define TEST_MAGIC 'x'                           //定义幻数
#define TEST_MAX_NR 2                            //定义命令的最大序数

//定义LED的魔幻数
#define LED1 _IO(TEST_MAGIC, 0)              
#define LED2 _IO(TEST_MAGIC, 1)
#define LED3 _IO(TEST_MAGIC, 2)
#define LED4 _IO(TEST_MAGIC, 3)



//#define REC_CMD  "./arecord -d4 -c1 -r16000 -traw -fS16_LE cmd.pcm"
#define REC_CMD  "arecord -d3 -c1 -r16000 -traw -fS16_LE cmd.pcm"
#define PCM_FILE "./cmd.pcm"
/* -d：录音时长（duration）
-c：音轨（channels）
-r：采样频率（rate）
-t：封装格式（type）
-f：量化位数（format） */
int said = 0;

void catch (int sig)
{
	if (sig == SIGPIPE)
	{
		printf("killed by SIGPIPE\n");
		exit(0);
	}
}


#define N 4
int board[4][4] = { 0 };//棋盘大小
char* music[] = { (char*)"/mnt/1.mp3",(char*)"/mnt/2.mp3" };
char* video[] = { (char*)"/mnt/1.mp4",(char*)"/mnt/2.mp4" };
char* bmp[] = { (char*)"/mnt/1.bmp",(char*)"/mnt/2.bmp",(char*)"/mnt/3.bmp",(char*)"/mnt/4.bmp" };
int i = 0;
int j = 0;
bool flag = 0;
bool flag1 = 0;

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
		printf("open picture_fd failed\n");
	}
	//4.读取颜色值 写入帧缓冲设备文件
	//略过文件的头
	unsigned char head[54] = { 0 };
	int ret = read(picture_fd, head, 54);
	if (ret == -1)
	{
		printf("read picture_fd's head failed\n");
	}
	//读取颜色值 
	unsigned char buf[800 * 480 * 3] = { 0 };
	ret = read(picture_fd, buf, 800 * 480 * 3);
	if (ret == -1)
	{
		printf("read picture_fd's colorvalue failed\n");
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
		printf("close picture_fd failed");
	}
}


void show_numbmp(char* pathname, int x, int y)
{
	//3.打开图片文件
	int picture_fd = open(pathname, O_RDWR);
	if (picture_fd < 0)
	{
		printf("open failed");
	}
	//4.读取颜色值 写入帧缓冲设备文件
	//略过文件的头
	unsigned char head[54] = { 0 };
	int ret = read(picture_fd, head, 54);
	if (ret == -1)
	{
		printf("read failed");
	}
	//读取颜色值 
	unsigned char buf[800 * 480 * 3] = { 0 };
	ret = read(picture_fd, buf, 100 * 100 * 3);
	if (ret == -1)
	{
		printf("read failed");
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
		printf("close failed");
	}
}


int main(int argc, char const* argv[]) // ./wav2pcm ubuntu-IP
{

	signal(SIGPIPE, catch);
	int id_num = 0;
	if (argc != 2)
	{
		printf("Usage: %s <ubuntu-IP>\n", argv[0]);
		exit(0);
	}

	int sockfd = init_sock(argv[1]); //tcp

	//打开并且初始化串口
	/*int serial_fd;
	serial_fd = open(DEV_PATH, O_RDWR | O_NOCTTY | O_NONBLOCK);
	if (serial_fd < 0)
	{
		fprintf(stderr, "Open Gec210_ttySAC2 fail!\n");
		return -1;
	}
	init_tty(serial_fd);

	//初始化UDP的socket
	//int udp_sockfd=udp_init();*/

	

	while (1)
	{
		// 1，调用arecord来录一段音频
		printf("please to start REC in 3s...\n");

		// 在程序中执行一条命令  “录音的命令”
		system(REC_CMD);

		// 2，将录制好的PCM音频发送给语音识别引擎
		send_pcm(sockfd, PCM_FILE);

		// 3，等待对方回送识别结果（字符串ID）
		xmlChar* id = wait4id(sockfd);

		if (id == NULL)
		{
			continue;
		}
		id_num = atoi((char*)id);
		if (id_num == 999)
		{
			printf("bye-bye!\n");
			goto exit;
		}
		if (id_num == 100)
		{
			printf("你好，主人！有什么吩咐\n");
			said = 1;  //唤醒它
			//system("madplay /home/master.mp3"); // 放一个语音文件

		}
		if (said == 1 && id_num != 100)
		{
			//send_data_to_8266(id_num);
			//网络发送的函数，把 id号发送到 网络中。

			printf("id: %d\n", id_num);

			if (id_num == 2) {// 看看自拍
				char cmd[25] = { 0 };
				sprintf(cmd, "%s", bmp[2]);
				show_bmp(cmd);
			}
			if (id_num == 7)//播放音乐
			{
				if (flag1 == 1) {
					system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
				}
				pid_t pid = fork();
				if (pid == 0) {
					char cmd[25] = { 0 };
					sprintf(cmd, "%s", bmp[i]);
					show_bmp((char*)cmd);
					char cmd1[25] = { 0 };
					sprintf(cmd1, "madplay %s", music[i]);
					system(cmd1);
					exit(0);
				}

				flag = 1;
			}
			if (id_num == 3)//下一首
			{
				++i;
				if (i >= 2) {
					i = 0;
				}
				char cmd[25] = { 0 };
				sprintf(cmd, "%s", bmp[i]);
				show_bmp((char*)cmd);
				if (flag == 1) {
					system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
				}
				pid_t pid = fork();
				if (pid == 0) {
					char cmd1[25] = { 0 };
					sprintf(cmd1, "madplay %s", music[i]);
					system(cmd1);
					exit(0);
				}

				flag = 1;
			}

			if (id_num == 4) {//上一首
				--i;
				if (i < 0) {
					i = 1;
				}
				char cmd[25] = { 0 };
				sprintf(cmd, "%s", bmp[i]);
				show_bmp((char*)cmd);
				if (flag == 1) {
					system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
				}
				pid_t pid = fork();
				if (pid == 0) {
					char cmd1[25] = { 0 };
					sprintf(cmd1, "madplay %s", music[i]);
					system(cmd1);
					exit(0);
				}

				flag = 1;
			}

			if (id_num == 8) {//播放视频
				if (flag == 1) {
					system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
				}
				pid_t pid = fork();
				if (pid == 0) {
					char cmd[25] = { 0 };
					sprintf(cmd, "mplayer %s", video[j]);
					system(cmd);
					exit(0);
				}

				flag1 = 1;
			}
			
			if (id_num == 5) { //下一个

				++j;
				if (j >= 2) {
					j = 0;
				}
				if (flag1 == 1) {
					system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
				}
				pid_t pid = fork();
				if (pid == 0) {
					char cmd[25] = { 0 };
					sprintf(cmd, "mplayer %s", video[j]);
					system(cmd);
					exit(0);
				}

				flag1 = 1;
			}

			if (id_num == 6)//下一个
			{
				--j;
				if (j < 0) {
					j = 1;
				}
				if (flag1 == 1) {
					system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
				}
				pid_t pid = fork();
				if (pid == 0) {
					char cmd[25] = { 0 };
					sprintf(cmd, "mplayer %s", video[j]);
					system(cmd);
					exit(0);
				}

				flag1 = 1;
			}
			else if (id_num == 9) { //打开游戏

			}

			said = 0;
		}
	}
	//串口打印数据
	//uart_send_data(serial_fd,id_num);
	//udp发送数据给esp8266
	//send_data_to_8266(id_num);


exit:

	//close(serial_fd);
	close(sockfd);
	return 0;
}

