#include <iostream>
#include <deque>
using namespace std;

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		deque<int> st;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			st.push_back(i);
		while (st.size() > 1) {
			cout << st.front() << " ";
			st.pop_front();
			st.push_back(st.front());
			st.pop_front();
		}
		cout << st.front() << " " << endl;
	}
	return 0;
}