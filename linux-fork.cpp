#include<iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main()
{
	pid_t pid = fork();
	if (pid > 0) //父进程
	{
		cout << "i father" << endl;
		cout << "son process's pid is " << pid << endl;
		char cmd[25] = { 0 };
		sprintf(cmd, "kill -9 %d", pid);
		cout << "cmd's contants is " << cmd << endl;
		system(cmd);

	}
	else if (pid == 0) //子进程
	{
		cout << "i son" << endl;
		exit(0);
	}
	cout << "hello" << endl;

	return 0;
}