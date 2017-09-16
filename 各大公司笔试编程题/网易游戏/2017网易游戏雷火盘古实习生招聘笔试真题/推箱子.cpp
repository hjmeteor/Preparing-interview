// [编程题] 推箱子
// 时间限制：1秒
// 空间限制：32768K
// 大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、1个目的地以及若干障碍，其余是空地。玩家可以往上下左右4个方向移动，但是不能移动出地图或者移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，当然，箱子也不能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。 
// 输入描述:
// 每个测试输入包含1个测试用例
// 第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
// 接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、#表示障碍、@表示目的地。
// 每个地图必定包含1个玩家、1个箱子、1个目的地。


// 输出描述:
// 输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。

// 输入例子1:
// 4 4
// ....
// ..*@
// ....
// .X..
// 6 6
// ...#..
// ......
// #*##..
// ..##.#
// ..X...
// .@#...

// 输出例子1:
// 3
// 11
#include <iostream>  
#include <queue>
#include <vector> 
#include <string>
using namespace std;

#define DIRECTSIZE 4  

int matrixx = 0, matrixy = 0;

struct node {
	int x;
	int y;
};
struct pb {
	int px, py;
	int bx, by;
};
struct dir {
	int xd;
	int yd;
}dir[DIRECTSIZE] = {{-1,0}, {1,0}, {0,1}, {0,-1}}; //下 上 右 左

vector<vector<char>> matrix;
bool valid(int x, int y) {
	if (x >= 0 && x < matrixx && y >= 0 && y < matrixy) {
		return true;
	}
	return false;
}

void bfs(int matrixx, int matrixy, vector<vector<char>> matrix)
{
	pb start;
	queue<pb> q;
	node end;
	vector<vector<vector<vector<int>>>> visit(matrixx, 
		vector<vector<vector<int>>>(matrixy, 
			vector<vector<int>>(matrixx, vector<int>(matrixy, 0))));
	for (int i = 0; i < matrixx; i++)
	{
		for (int j = 0; j < matrixy; j++)
		{
			if (matrix[i][j] == 'X') {
				start.px = i;
				start.py = j;
			}
			else if (matrix[i][j] == '@') {
				end.x = i;
				end.y = j;
			}
			else if (matrix[i][j] == '*') {
				start.bx = i;
				start.by = j;
			}
		}
	}
	visit[start.px][start.py][start.bx][start.by] = 1;
	q.push(start);
	while (!q.empty()) {
		pb front = q.front(); 
		q.pop();
		for (int i = 0; i<DIRECTSIZE; i++) {
			//cout << '3';
			int nextx = front.px + dir[i].xd;
			int nexty = front.py + dir[i].yd;
			int nextbx = front.bx + dir[i].xd;
			int nextby = front.by + dir[i].yd;
			//cout << '[' << nextx << ',' << nexty << ',' << nextbx << ',' << nextby << ']' << endl;
			if (valid(nextx, nexty) && matrix[nextx][nexty] != '#' && (nextx != front.bx ||
				nexty != front.by) &&
				visit[nextx][nexty][front.bx][front.by] == 0) {
				//cout << '1';
				visit[nextx][nexty][front.bx][front.by] =
					visit[front.px][front.py][front.bx][front.by] + 1;
				pb now;
				now.px = nextx;
				now.py = nexty;
				now.bx = front.bx;
				now.by = front.by;
				//cout << '(' << now.px << ',' << now.py << ',' << now.bx << ',' << now.by << ')' << endl;
				q.push(now);

				continue;
			}
			else if (nextx == front.bx && nexty == front.by && valid(nextbx, nextby) &&
				matrix[nextbx][nextby] != '#' && visit[nextx][nexty][nextbx][nextby] == 0){
				//cout << '2';
				visit[nextx][nexty][nextbx][nextby] =
					visit[front.px][front.py][front.bx][front.by] + 1;
				if (matrix[nextbx][nextby] == '@') {
					cout << visit[nextx][nexty][nextbx][nextby] - 1 << endl;
					return;
				}
				pb now;
				now.px = nextx;
				now.py = nexty;
				now.bx = nextbx;
				now.by = nextby;
				//cout << '(' << now.px << ',' << now.py << ',' << now.bx << ',' << now.by << ')' << endl;
				q.push(now);
				continue;
			}
		} 
	}
	int a = -1;
	cout << a <<endl;
	return;
}

int main(void)
{
	cin >> matrixx >> matrixy;
	cin.ignore();
	vector<vector<char>> matrix(matrixx, vector<char>(matrixy, 's'));
	string* a = new string[matrixx];
	for (int i = 0; i < matrixx; i++) {
		getline(cin, a[i]);
	}
	for (int i = 0; i < matrixx; i++)
	{
		for (int j = 0; j < matrixy; j++)
		{
			//char t;
			//cin >> t;
			//matrix[i][j] = t;
			matrix[i][j] = a[i][j];
		}
	}
	delete []a;
	a = NULL;
	bfs(matrixx, matrixy, matrix); // 开始搜索  
	return 0;
}