#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 10000

vector<int> s;
/*
  邻接矩阵结构
*/
int r[MAX][MAX] = {0};
int visited[MAX] = {0};
int n, i, j;

/*
  邻接表结构
typedef char VertexType;  
typedef struct node {   //边表节点  
   int adjvex;  
   node* next;  
}EdgeNode;  
  
typedef struct {     //顶点表节点 
   VertexType vertex;  
   EdgeNode* firstedge;  
}VertexNode;  
  
typedef VertexNode AdjList[MaxVertexNum];  
  
typedef struct {   
    AdjList adjlist;  
    int n,e;  
}ALGraph; 
*/

void showhelp() {
	cout << "--------------------------------" << endl;
	cout << "input command:" << endl;
	cout << "'a': add relation(i,j)" << endl;
	cout << "'s': show all relations" << endl;
	cout << "'d': dfs traversal" << endl;
	cout << "'b': bfs traversal" << endl;
	cout << "--------------------------------" << endl;
}

void dfs_travel(int num) {
	if (num < 0 || num >= n) {
		cout << "input error!" << endl;
		exit(0);
	} else {

		for (i = 0; i < s.size(); i++)
			if (s[i] == num)
				break;
		if (i == s.size())
			s.push_back(num);

		visited[num] = 1;
		for (int i = 0; i < n; i++)
			if (r[num][i] && !visited[i]) {
				cout << "(" << num << "," << i << ")"<< endl;
				dfs_travel(i);
				//visited[num][i] = visited[i][num] = 0;
			}
	}
}

void dfs() {
	cout << "input first num:" << endl;
	int num;
	cin >> num;
	cout << "dfs_travel:" << endl;
	dfs_travel(num);
	for (i = 0; i < n; i++)
		visited[i] = 0;

	cout << "dfs_order: ";
    vector<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
		cout << *it << " ";
	cout << endl;
	s.clear();
}

void bfs_travel(int num) {
	cout << "bfs_travel:" << endl;
	queue<int> qu;
	qu.push(num);
	while(qu.size()) {
		int x = qu.front();
		visited[x] = 1;
		for (i = 0; i < n; i++)
			if (r[x][i] && !visited[i]) {
				cout << "(" << x << "," << i << ")" << endl;
				qu.push(i);
			for (j = 0; j < s.size(); j++)
				if (s[j] == i)
					break;
			if (j == s.size())
				s.push_back(i);
			}
		qu.pop();
	}
}

void bfs() {
	cout << "input first num:" << endl;
	int num;
	cin >> num;
	bfs_travel(num);

	cout << "bfs_order: " << num << " ";
    vector<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
		cout << *it << " ";
	cout << endl;
	s.clear();
}

void show() {
	cout << "  ";
	for (i = 0; i < n; i++)
		cout << " " << i;
	cout << endl << "  ";
	for (i = 0; i < n; i++)
		cout << " -";
	cout << endl;
	for (i = 0; i < n; i++) {
		cout << i << "| ";
		for (j = 0; j < n; j++)
			cout << r[i][j] << " ";
		cout << endl;
	}
}

int main() {

	cout << "input size: " << endl;
	cin >> n;
/*
	r[1][2]=r[1][3]=1;
	r[4][2]=r[4][3]=1;
	r[2][1]=r[2][4]=1;
	r[3][1]=r[3][4]=1;

	r[1][2]=r[1][3]=1;
	r[1][4]=r[2][3]=1;
	r[3][4]=r[2][5]=1;
	r[3][6]=r[4][7]=1;
	r[5][6]=r[6][7]=1;

	r[2][1]=r[3][1]=1;
	r[4][1]=r[3][2]=1;
	r[4][3]=r[5][2]=1;
	r[6][3]=r[7][4]=1;
	r[6][5]=r[7][6]=1;
*/
	showhelp();
	while (true) {
		int cmd;
		char c;
		cin >> c;

		if (c == 'a') {
			cin >> i >> j;
			r[i][j] = r[j][i] = 1;
		} else if (c == 's') {
			show();
		} else if (c == 'd') {		
			dfs();
		} else if (c == 'b') {
			bfs();
		} else if (c == 'h') {
			showhelp();
		}  else {
			cout << "Unknown command" << endl;
		}

	}

	return 0;
}

