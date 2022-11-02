#include<iostream>
using namespace std;
void test1() {
	int currval = 0, val = 0;
	if (cin >> currval) {
		int cnt = 1;
		while (cin >> val) {
			if (val == currval) {
				cnt++;
			}
			else {
				cout << currval << " occurs " << cnt << " times" << endl;
				currval = val;
				cnt = 1;
			}
		}
		cout << currval << " occurs " << cnt << " times" << endl;
	}
	else {
		cerr << "No data?!" << endl;
	}
}
int main() {
	test1();
	return 0;
}