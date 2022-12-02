#include<iostream>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

//初始化串口
//file: 串口所对应的文件名
//baudrate：波特率
int init_serial(const char* file, int baudrate)
{
	int fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		cerr << "open device error:";
		return -1;
	}

	struct termios myserial;
	//清空结构体
	memset(&myserial, 0, sizeof(myserial));
	//O_RDWR               
	myserial.c_cflag |= (CLOCAL | CREAD);
	//设置控制模式状态，本地连接，接受使能
	//设置 数据位
	myserial.c_cflag &= ~CSIZE;   //清空数据位
	myserial.c_cflag &= ~CRTSCTS; //无硬件流控制
	myserial.c_cflag |= CS8;      //数据位:8

	myserial.c_cflag &= ~CSTOPB;//   //1位停止位
	myserial.c_cflag &= ~PARENB;  //不要校验
	//myserial.c_iflag |= IGNPAR;   //不要校验
	//myserial.c_oflag = 0;  //输入模式
	//myserial.c_lflag = 0;  //不激活终端模式

	switch (baudrate)
	{
	case 9600:
		cfsetospeed(&myserial, B9600);  //设置波特率
		cfsetispeed(&myserial, B9600);
		break;
	case 115200:
		cfsetospeed(&myserial, B115200);  //设置波特率
		cfsetispeed(&myserial, B115200);
		break;
	case 19200:
		cfsetospeed(&myserial, B19200);  //设置波特率
		cfsetispeed(&myserial, B19200);
		break;
	}

	/* 刷新输出队列,清除正接受的数据 */
	tcflush(fd, TCIFLUSH);

	/* 改变配置 */
	tcsetattr(fd, TCSANOW, &myserial);

	return fd;
}

int main() {

	int fd = init_serial("/dev/ttySAC2", 9600);
	unsigned char cmd[3] = { 0xA5, 0x83, 0x28 };
	int ret = write(fd, cmd, 3);
	if (ret == -1) {
		cout << "Write failed" << endl;
	}
	
	unsigned char data[24] = { 0 };
	while (1) {
		sleep(1);
		ret = read(fd, data, 24);
		if (ret != 24) {
			cout << "Read failed" << endl;
			continue;
		}
		if (data[0] == 0x5A && data[1] == 0x5A && data[2] == 0x15) {
			int lux = data[4] << 24 | data[5] << 16 | data[6] << 8 | data[7];
			lux = lux / 100;
			cout << "lux is " << lux << endl;

			int t = data[13] << 8 | data[14];
			t = t / 100;
			cout << "t is " << t << "C" << endl;

			int pa = data[15] << 24 | data[16] << 16 | data[17] << 8 | data[18];
			pa = pa / 100;
			cout << "pa is " << pa << "pa" << endl;

			int hum = data[19] << 8 | data[20];
			hum /= 100;
			cout << "hum is " << hum << "%" << endl;

			int h = data[21] << 8 | data[22];
			cout << "h is " << h << "m" << endl;
		}
	}
	return 0;
}