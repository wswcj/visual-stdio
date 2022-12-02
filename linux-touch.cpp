#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<linux/input.h>
using namespace std;


int* p = NULL;
int main() {
	
	int fd1 = open("/dev/input/event0", O_RDWR);
	if (fd1 < 0) {
		cout << "Open failed" << endl;
	}


	struct input_event ev;
	while (1) {

		int ret = read(fd1, &ev, sizeof(ev));
		if (ret == -1) {
			cout << "Read failed" << endl;
			continue;
		}
		cout << "ev.type = " << ev.type << " ev.code = " << ev.code << " ev.value = " << ev.value << endl;
	}
	
	return 0;
}