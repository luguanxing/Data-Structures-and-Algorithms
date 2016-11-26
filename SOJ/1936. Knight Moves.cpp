#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct point {
	int x, y;
	int step;
};

point oper[] = {{2, -1}, {2, 1},  {-2, 1}, {-2, -1},
				{1, 2},  {1, -2}, {-1, 2}, {-1, -2}};
bool visited[8][8]; 

int bfs(point start, point end) {
	queue<point> qu;
	qu.push(start);
	int stop = false;
	visited[start.y][start.x] = true;
	while (qu.size() && !stop) {
		point p = qu.front();
		for (int i = 0; i < 8; i++) {
			point t;
			t.x = p.x + oper[i].x;
			t.y = p.y + oper[i].y;
			t.step = p.step + 1;
			if (t.x < 0 || t.x >= 8 || t.y < 0 || t.y >= 8)
				continue;
			if (visited[t.y][t.x])
				continue;
			visited[t.y][t.x] = true;
			if (t.x == end.x && t.y == end.y) {
				stop = t.step;
				break;
			}
			qu.push(t);
		}
		qu.pop();
	}
	return stop;
}

int main () {
	point start, end;
	int i, cas;
	cin >> cas;
	getchar();
	char buff[20];
	while(cas--) {
		gets(buff);
		start.x = buff[0]-'a';
		start.y = buff[1]-'1';
		start.step = 0;
		end.x = buff[3]-'a';
		end.y = buff[4]-'1';
		end.step = 0;
		for (i = 0; i < 8; i++)
			memset(visited[i], 0, 8);
		cout << "To get from "<< buff[0] << buff[1] <<" to "<< buff[3] << buff[4] <<" takes "<< bfs(start, end) <<" knight moves." << endl;
	}
	return 0;
}