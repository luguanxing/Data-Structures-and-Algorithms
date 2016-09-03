#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int cas;
	int i, a[10];
	cin >> cas;
	while (cas) {
		for (i = 0; i < 10; i++)
			a[i] = i + 1;
		do {
			for (i = 0; i < cas; i++)
				cout << a[i] << " ";
			cout << endl;
		} while (std::next_permutation(a, a + cas));
		cin >> cas;
	}
	return 0;
}