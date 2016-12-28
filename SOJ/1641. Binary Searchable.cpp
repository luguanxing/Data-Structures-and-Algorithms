#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[10005];
int n;

bool isok(int k) {
	int i;
	for (i = k; i >= 0 ; i--)
		if (a[i] <= a[k])
			continue;
		else
			return false;
	for (i = k; i < n ; i++)
		if (a[k] <= a[i])
			continue;
		else
			return false;
	return true;
}

int main() {
	while(cin >> n) {
		int sum = 0;
		int i;
		for (i = 0; i < n; i++)
			cin >> a[i];
		for (i = 0; i < n; i++)
			if (isok(i))
				sum++;
		cout << sum << endl;
	}
	return 0;
}