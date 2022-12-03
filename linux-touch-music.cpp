#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<linux/input.h>
#include<cstdlib>
using namespace std;

int main() {

	int fd1 = open("/dev/input/event0", O_RDWR);
	if (fd1 < 0) {
		cout << "Open failed" << endl;
	}

	int x, y, x_start, y_start, x_stop, y_stop;
	struct input_event ev;
	int count = 1;
	int num = 1;
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
					if (count < 3) {
						if (count == 1) {
							system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("madplay 2.mp3");
								exit(0);
							}
							count++;
						}
						else if (count == 2) {
							system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("madplay 3.mp3");
								exit(0);
							}
							count++;
						}
					}
				}
				else  					//左滑
				{
					if (count > 0) {
						if (count == 3) {
							system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("madplay 2.mp3");
								exit(0);
							}
							count--;
						}
						else if (count == 2) {
							system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("madplay 1.mp3");
								exit(0);
							}
							count--;
						}
					}
				}
			}
			else if (abs(x_stop - x_start) < abs(y_stop - y_start) && abs(y_stop - y_start) > 50)  //Y方向的事件
			{
				if (y_stop - y_start > 0)  //下滑
				{
					if (num > 0) {
						if (num == 3) {
							system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("mplayer 2.mp4");
								exit(0);
							}
							num--;
						}
						else if (num == 2) {
							system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("mplayer 1.mp4");
								exit(0);
							}
							num--;
						}
					}
				}
				else  					//上滑
				{
					if (num < 3) {
						if (num == 1) {
							system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("mplayer 2.mp4");
								exit(0);
							}
							num++;
						}
						else if (num == 2) {
							system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
							pid_t pid = fork();
							if (pid == 0) {
								system("mplayer 3.mp4");
								exit(0);
							}
							num++;
						}
					}
				}
			}

			else //点击  
			{
				if (x_stop >= 0 && x_stop <= 150 && y_stop >= 100 && y_stop <= 380) {
					system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					pid_t pid = fork();
					if (pid == 0) {
						system("madplay 1.mp3");
						exit(0);
					}
				}
				if (x_stop >= 600 && x_stop <= 800 && y_stop >= 100 && y_stop <= 380) {
					system("ps | grep 'madplay' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					system("ps | grep 'mplayer' | awk '!/grep/{print $1}' | xargs  kill -9 2> /dev/null");
					pid_t pid = fork();
					if (pid == 0) {
						system("mplayer 1.mp4");
						exit(0);
					}
				}
			}
		}

	}

	return 0;
}