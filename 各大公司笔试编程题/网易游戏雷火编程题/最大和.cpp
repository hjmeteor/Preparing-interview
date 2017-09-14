// [编程题] 最大和
// 时间限制：1秒
// 空间限制：32768K
// 在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，四种方向的直线连续D个数字的和里面最大的值 
// 输入描述:
// 每个测试输入包含1个测试用例，第一行包括两个整数 N 和 D :
// 3 <= N <= 100
// 1 <= D <= N
// 接下来有N行，每行N个数字d:
// 0 <= d <= 100


// 输出描述:
// 输出一个整数，表示找到的和的最大值

// 输入例子1:
// 4 2
// 87 98 79 61
// 10 27 95 70
// 20 64 73 29
// 71 65 15 0

// 输出例子1:
// 193
#include<iostream>
#include<string>
using namespace std;
int matrix = 0;
int num = 0;
int max = 0;
void rowadd(int** p, int i, int j)    //row add compare  
{
	int result = 0;
	for (int k = 0; k < num; ++k)
	{
		result = result + p[i][j + k];
	}
	if (result > max)
	{
		max = result;
	}
}
void coladd(int** p, int i, int j)    //line add compare  
{
	int result = 0;
	for (int k = 0; k < num; ++k)
	{
		result = result + p[i + k][j];
	}
	if (result > max)
	{
		max = result;
	}
}
void leftuprightdown(int** p, int i, int j)    //leftToRight add compare  
{
	int result = 0;
	for (int k = 0; k < num; ++k)
	{
		result = result + p[i + k][j + k];
	}
	if (result > max)
	{
		max = result;
	}
}
void rightupleftdown(int** p, int i, int j)    //RightUpToLeftDownAdd add compare  
{
	int result = 0;
	for (int k = 0; k < num; ++k)
	{
		result = result + p[i + k][j - k];
	}
	if (result > max)
	{
		max = result;
	}
}
int main() {
	cin >> matrix;
	cin >> num;
	int** p = new int*[matrix];
	for (int i = 0; i < matrix; ++i) {
		p[i] = new int[matrix];
	}
	for (int i = 0; i < matrix; ++i) {
		for (int j = 0; j < matrix; ++j)
		{
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < matrix; ++i) {
		for (int j = 0; j < matrix; ++j)
		{
			if (j <= matrix - num) {
				rowadd(p, i, j);
			}
			if (i <= matrix - num) {
				coladd(p, i, j);
			}
			if (j <= matrix - num && i <= matrix - num) {
				leftuprightdown(p, i, j);
			}
			if (i <= matrix - num && j >= num - 1) {
				rightupleftdown(p, i, j);
			}
		}
	}
	cout << max << endl;
	return 0;
}
