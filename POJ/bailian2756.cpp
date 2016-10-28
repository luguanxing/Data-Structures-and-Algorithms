#include <iostream>
using namespace std;
	
int main() {
	int a, b;
	cin >> a >> b;
	while (a != b) {
		while (a < b)
			b >>= 1;
		while (a > b)
			a >>= 1;
	}
	cout << a << endl;
	return 0;
}