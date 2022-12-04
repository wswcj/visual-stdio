#include<iostream>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<linux/input.h>
#include <stdlib.h>
using namespace std;
#define N 1024 / 800
#define M 600 / 400

char* music[] = { (char*)"1.mp3",(char*)"2.mp3", (char*)"3.mp3" };
int i = 0;
bool flag = 0;

int main() {

	int fd1 = open("/dev/input/event0", O_RDWR);
	if (fd1 < 0) {
		cout << "Open failed" << endl;
	}

	int x, y, x_start, y_start, x_stop, y_stop;
	struct input_event ev;

	while (1)
	{

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
					++i;
					if (i >= 3) {
						i = 0;
					}
					if (flag == 1) {
						system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					}
					pid_t pid = fork();
					if (pid == 0) {
						char cmd[25] = { 0 };
						sprintf(cmd, "madplay %s", music[i]);
						system(cmd);
						exit(0);
					}
					
					flag = 1;
				}
				else  					//左滑
				{
					--i;
					if (i < 0) {
						i = 2;
					}
					if (flag == 1) {
						system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					}
					pid_t pid = fork();
					if (pid == 0) {
						char cmd[25] = { 0 };
						sprintf(cmd, "madplay %s", music[i]);
						system(cmd);
						exit(0);
					}
					
					flag = 1;
				}
			}
			else if (abs(x_stop - x_start) < abs(y_stop - y_start) && abs(y_stop - y_start) > 50)  //Y方向的事件
			{
				if (y_stop - y_start > 0)  //下滑
				{
					
				}
				else  					//上滑
				{
					
				}
			}

			else //点击  
			{
				if (x_stop >= 200 * N && x_stop <= 300 * N && y_stop >= 280 * M && y_stop <= 380 * M) {   //下一首
					++i;
					if (i >= 3) {
						i = 0;
					}
					if (flag == 1) {
						system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					}
					pid_t pid = fork();
					if (pid == 0) {
						char cmd[25] = { 0 };
						sprintf(cmd, "madplay %s", music[i]);
						system(cmd);
						exit(0);
					}
					
					flag = 1;
				}
				if (x_stop >= 500 * N && x_stop <= 600 * N && y_stop >= 280 * M && y_stop <= 380 * M) {
					
					--i;
					if (i < 0) {
						i = 2;
					}
					if (flag == 1) {
						system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					}
					pid_t pid = fork();
					if (pid == 0) {
						char cmd[25] = { 0 };
						sprintf(cmd, "madplay %s", music[i]);
						system(cmd);
						exit(0);
					}
					
					flag = 1;
				}

			}
		}

	}

	return 0;
}