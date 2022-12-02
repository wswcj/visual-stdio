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
	while (1)
	{

		int ret = read(fd1, &ev, sizeof(ev));
		if (ret == -1)
		{
			cout << "Read failed" << endl;
			continue;
		}
		cout << "ev.type = " << ev.type << " ev.code = " << ev.code << " ev.value = " << ev.value << endl;
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
			cout << "按下" << endl;
		}
		else if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0) //表示弹起来了
		{
			x_stop = x;
			y_stop = y;
			cout << "弹起" << endl;

			if (abs(x_stop - x_start) > abs(y_stop - y_start) && abs(x_stop - x_start) > 50)  //X方向的事件
			{
				if (x_stop - x_start > 0)  //右滑
				{
					cout << "右滑" << endl;
				}
				else  					//左滑
				{
					cout << "左滑" << endl;
				}
			}
			else if (abs(x_stop - x_start) < abs(y_stop - y_start) && abs(y_stop - y_start) > 50)  //Y方向的事件
			{
				if (y_stop - y_start > 0)  //下滑
				{
					cout << "下滑" << endl;
				}
				else  					//上滑
				{
					cout << "上滑" << endl;
				}
			}

			else //点击  
			{
				cout << "点击" << endl;
			}
		}

	}

	return 0;
}