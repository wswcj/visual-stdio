#include<iostream> 
using namespace std;
class Solution {
public:
	void getNext(int next[], string s) {
		int j = -1;
		next[0] = -1;
		int i = 0, len = s.length();
		while (i < len - 1) {
			if (j == -1 || s[i] == s[j]) {
				i++;
				j++;
				next[i] = j;
			}
			else {
				j = next[j];
			}
		}
	}
	int strStr(string haystack, string needle) {
		int len1 = haystack.length(), len2 = needle.length();
		int* next = new int[len2];
		getNext(next, needle);
		int i = 0, j = 0;
		while (i < len1 && j < len2) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (j >= len2) {
			return i - len2;
		}
		return -1;
	}
	string haystack;
	string needle;
};
void test4() {
	Solution s1;
	s1.haystack = "hello";
	s1.needle = "ll";
	int num = s1.strStr(s1.haystack, s1.needle);
	cout << num << endl;
}
int main() {
	test4();
	return 0;
}