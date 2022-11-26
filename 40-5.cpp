#include<iostream>
using namespace std;

int main() {
	int a;
	cin.unsetf(ios::dec);
	cin.setf(ios::hex);
	cin >> a;
	cout << a << endl;
	return 0;
}