#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int iskh(char x) {
	switch (x) {
		case '{':
			return 1;
			break;
		case '}':
			return 2;
			break;
		case '(':
			return 3;
			break;
		case ')':
			return 4;
			break;
		case '[':
			return 5;
			break;
		case ']':
			return 6;
			break;
		default:
			return 0;
	}
}

int main() {
	int cas;
	cin >> cas;
	while(cas--) {
		stack<int> st;
		string s;
		cin >> s;
		bool succeed = true;
		for (int i = 0; i < s.length(); i++) {
			int result = iskh(s[i]);
			if (!result)
				continue;
			else if (result == 1 || result == 3 || result == 5)
				st.push(s[i]);
			else {
				if (result == 2) {
					if (st.size() && iskh(st.top()) == 1) {
						st.pop();
						continue;
					}
					else {
						succeed = false;
						break;
					}	
				}
				if (result == 4) {
					if (st.size() && iskh(st.top()) == 3) {
						st.pop();
						continue;
					}
					else {
						succeed = false;
						break;
					}	
				}
				if (result == 6) {
					if (st.size() && iskh(st.top()) == 5) {
						st.pop();
						continue;
					}
					else {
						succeed = false;
						break;
					}	
				}
			}
		}
		if (succeed && !st.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}