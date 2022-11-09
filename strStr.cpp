#include<iostream> 
using namespace std;
class Solution {
public:
	void getNext(int next[], string s) {
		int j = -1;
		next[0] = -1;
		int i = 0;
		while (i < s.length() - 1) {
			if (j == -1 || s[j] == s[i]) {
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
		int* next = new int[needle.size()];
		getNext(next, needle);
		if (needle.length() == 0) {
			return 0;
		}
		int i = 0, j = 0;
		int len1 = haystack.size();
		int len2 = needle.size();
		while (i < len1 && j < len2) {
			if (j == -1 || haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (j >= needle.length()) {
			return i - needle.length();
		}
		else {
			return -1;
		}
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