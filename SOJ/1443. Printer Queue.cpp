#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
int main() {
	deque<int> a, b;
	int i, j, n, m, x, ct, max, cas;
	cin >> cas;
	while (cas--) {
		cin >> n >> m;
		for (i = 0; i < n; i++) {
			cin >> x;
			a.push_back(x);
			b.push_back(0);
		}
		b[m] = 1;
		ct = 0;
		deque<int>::iterator it;
		while (true) {
			max = 0;
			for (it = a.begin(), i = 0; it != a.end(); it++, i++)
				if ( (*it) > max ) {
					max = (*it);
					x = i;
				}
			while (x--) {
				a.push_back(a.front()); a.pop_front();
				b.push_back(b.front()); b.pop_front();
			}
			if (b[0])
				break;
			a.pop_front();
			b.pop_front();
			ct++;
		}
		cout << ct + 1 << endl;
		a.clear();
		b.clear();
	}
	return 0;
}
	