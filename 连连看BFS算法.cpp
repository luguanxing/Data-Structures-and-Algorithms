#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

int chessdata[5][5] = {
	{6, 0, 0, 6, 1},
	{2, 0, 0, 3, 1},
	{3, 5, 0, 0, 0},
	{1, 1, 0, 2, 5},
	{6, 0, 0, 0, 1},
};

struct point {
	int x, y, direct;	//	x, y为位置, direct为走的时候的方向
	int step, hp;
};
point P, N, goal;
point oper[4] = {{0, -1, 1}, {0, 1, 2}, {1, 0, 3}, {-1, 0, 4}};



int llk_bfs(int y1, int x1, int y2, int x2) {	//	用BFS检测(y1,x1) 到 (y2,x2) 有没有转折2次以内的路径

	bool cango[50][50], isvisit[50][50];
	int t, row = 5, col = 5;	//	注意col为竖行数, row为横行数	

	int temp1 = chessdata[y1][x1];
	int temp2 = chessdata[y2][x2];
	
	chessdata[y1][x1] = 'S';
	chessdata[y2][x2] = 'E';
	
	for (int i = 0; i < row; i++) {		//	对地图的标记
		for (int j = 0; j < col; j++) {
			isvisit[i][j] = false;
			t = chessdata[i][j];
			if (t == 0) {
				cango[i][j] = true;
			} else if (t == 'S') {
				N.y = i;
				N.x = j;
				cango[i][j] = true;
				isvisit[i][j] = true;
			} else if (t == 'E') {
				goal.y = i;
				goal.x = j;
				cango[i][j] = true;
			} else {
				cango[i][j] = false;
			}
		}
	}

	N.step = 0;
	N.hp = 2;	//	转折最多为2次
	N.direct = 0;


	queue<point> Q;
	Q.push(N);
	while (!Q.empty()) {	//	BFS遍历S点到E点的所有路径
		N = Q.front();
		Q.pop();
		if (N.x == goal.x && N.y == goal.y) {
			chessdata[y1][x1] = temp1;
			chessdata[y2][x2] = temp2;
			return N.step;
		}
		for (int i = 0; i < 4; i++) {
			P.x = N.x + oper[i].x;
			P.y = N.y + oper[i].y;
			P.step = N.step + 1;
			P.direct = oper[i].direct;
			P.hp = N.hp;
			if (P.direct != N.direct && N.direct != 0)
				P.hp -= 1;
			if (P.x >= 0 && P.x <= col && P.y >= 0 && P.y <= row	//	对边界,重复和转折次数的限制
					&& !isvisit[P.y][P.x] && cango[P.y][P.x] && P.hp >= 0) {
				isvisit[P.y][P.x] = true;
				Q.push(P);
			}
		}
	}
	chessdata[y1][x1] = temp1;
	chessdata[y2][x2] = temp2;		
	return -1;
}

int main() {
	int y1, x1, y2, x2;
	cin >> y1 >> x1 >> y2 >> x2;	//	输入要检测的两个位置
 	cout << llk_bfs(y1, x1, y2, x2) << endl;
 	return 0;
}
