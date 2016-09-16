#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int a[20][20];

int nextx(int k) {
	if (k + 1 >= n)
		return 0;
	return k + 1;
}

int nexty(int k) {
	if (k - 1 >= 0)
		return k - 1;
	return n - 1;
}

int main() {
	int i, j;
	cin >> n;
	if (n <= 0 || n > 20 || n % 2 == 0) {
		cout << "invalid num!\n";
		return 0;
	}

	for (i = 0; i < n; i++)	
		for (j = 0; j < n; j++)
			a[i][j] = 0;

	a[0][n / 2] = 1;
	int ct = 1;

	int y = 0;
	int x = n / 2;
	while (ct != n * n) {
		if (a[nexty(y)][nextx(x)] == 0) {
			a[nexty(y)][nextx(x)] = ++ct;
			y = nexty(y);
			x = nextx(x);
		} else {
			a[y+1][x] = ++ct;
			y = y + 1;
		}
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%2d ", a[i][j]);
		cout << endl;
	}

	return 0;
}
