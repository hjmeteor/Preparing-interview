// [编程题] 字符串编码
// 时间限制：1秒
// 空间限制：32768K
// 给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。 
// 输入描述:
// 每个测试输入包含1个测试用例
// 每个测试用例输入只有一行字符串，字符串只包括大写英文字母，长度不超过10000。


// 输出描述:
// 输出编码后的字符串

// 输入例子1:
// AAAABCCDAA

// 输出例子1:
// 4A1B2C1D2A

#include<iostream>
#include<string>
using namespace std;
int main() {
	string s = "";
	cin >> s;
	char last = '\0';
	string result = "";
	int count = 0;
	for (int i = 0; i < s.length() + 1; i++) {
		if (s[i] == last) {
			count++;
		}
		else if (s[i] == '\0') {
			char cnum[10001];
			string snum = "";
			sprintf_s(cnum, "%d", count);
			snum = cnum;
			result += snum + last;
			count = 1;
		}
		else {
			if (last == '\0') {
				count = 1;
			}
			else {
				char cnum[10001];
				string snum = "";
				sprintf_s(cnum, "%d", count);
				snum = cnum;
				result += snum + last;
				count = 1;
			}

		}
		last = s[i];
	}
	cout << result << endl;
	return 0;
}
