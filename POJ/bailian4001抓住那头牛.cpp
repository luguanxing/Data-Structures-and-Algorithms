#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000

int n, k;
int visited[MAX+5];	//ÕâÀï¿Óµù

bool checkside(int p) {
	if (0 <= p && p <= MAX)
		return true;
	else
		return false;
}

void bfs() {
	queue<int> qu;
	qu.push(n);
	visited[n] = 1;
	while (qu.size()) {
		int front = qu.front();
		qu.pop();
		if (front == k) {
			cout << visited[front]-1 << endl;
			break;
		}
		if (checkside(front+1) && !visited[front+1]) {
			visited[front+1] = visited[front] + 1;
			qu.push(front+1);
		}
		if (checkside(front-1) && !visited[front-1]) {
			visited[front-1] = visited[front] + 1;
			qu.push(front-1);
		}
		if (checkside(front*2) && !visited[front*2]) {
			visited[front*2] = visited[front] + 1;
			qu.push(front*2);
		}  
	}
}

int main() {
	cin >> n >> k;
	bfs();
	return 0;
}  