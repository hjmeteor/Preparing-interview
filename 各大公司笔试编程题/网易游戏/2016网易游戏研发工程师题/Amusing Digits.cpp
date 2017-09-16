// Amusing Digits

// 问题描述

// 给定一个数串，从中选出尽可能多的“9706”子串，要求每个digit的相对先后顺序不变且每个digit只能用一次，问最多可以选出多少个9706子串。
// 样例输入

// 4 
// 6097 
// 97069706 
// 997776600069 
// 123901370997606
// 样例输出

// 0 
// 2 
// 1 
// 2
#include <iostream>
#include <string>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int slen = s.length();
		int c9 = 0, c7 = 0, c0 = 0, c6 = 0;
		for (int i = 0; i < slen; i++) {
			switch (s[i]) {
				case '9': c9++; break;
				case '7': 
					if (c7 < c9) {
						c7++;
					}
					break;
				case '0':
					if (c0 < c7) {
						c0++;
					}
				case '6':
					if (c6 < c0) {
						c6++;
					}
			}
		}
		cout << c6 << endl;
	}
	return 0;
}