// 给定一个字符串，仅有圆括号，大写字母和数字组成。字串的数字表示它前面的字母或者括号中的模式的个数，如A2表示AA，(BC)3表示BCBCBC；允许复合，如(A3(BC)2)2表示AAABCBCAAABCBC。求给定字符串展开后的长度（即不包含数字和括号的表示的长度）。
// 样例输入

// 4 
// (AA)2A 
// ((A2B)2)2G 
// WANGYI 
// A2BC4D2
// 样例输出

// 5 
// 13 
// 6 
// 9
#include <iostream>
#include <string>
using namespace std;
bool isdigit(char d){
    if(d >= '0' && d <= '9'){
        return true;
    }
    else{
        return false;
    }
}
bool isalpha(char a){
    if((a >= 'a' && d <= 'z' )||(a >= 'A' && a <= 'Z')){
        return true;
    }
    else{
        return false;
    }
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int slen = s.length();
		for (int i = 0; i < slen; i++) {
            if(s[i] == )
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