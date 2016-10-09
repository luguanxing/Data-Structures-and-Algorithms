#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;
vector< stack<int> > stacks;
int num;

void show() {
	cout << "--------------------------------\n";
	cout << "sideA : ";
	for (unsigned int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	for (unsigned int i = 0; i < stacks.size(); i++) {
		stack<int> st = stacks[i];
		stack<int> st2;
		cout << "stacks[" << i << "] : ";
		while (st.size()) {
			st2.push(st.top());
			st.pop();
		}
		while (st2.size()) {
			cout << st2.top() << " ";
			st2.pop();
		}
		cout << endl;
	}
	cout << "sideB : ";
	for (unsigned int i = 0; i < b.size(); i++)
		cout << b[i] << " ";
	cout << endl;
	cout << "--------------------------------\n";
}

void pushad(int n, int x) {
	if (stacks.size() > n)
		stacks[n].push(x);
	else {
		stack<int> tempstack;
		tempstack.push(x);
		stacks.push_back(tempstack);
	}
}

int where(int x) {
	if (find(a.begin(), a.end(), x) != a.end())
		return -1;
	for (unsigned int i = 0; i < stacks.size(); i++) {
		stack<int> st = stacks[i];
		while (st.size()) {
			if (st.top() == x)
				return i;
			st.pop();
		}
	}

}

void stacksort() {
	int n = a.size();	//数字1-n
	int x = 1;
	while (x <= n) {	//以找x为中心
		int p = where(x);
		if (p == -1) {		//在a区栈
			while (a[a.size() - 1] != x) {
				pushad(0, a[a.size() - 1]);
				a.erase(a.end() - 1);
			}
			show();
			b.push_back(x);
			a.erase(a.end() - 1);
			show();
		}
		else {			//第p个栈
			while (stacks[p].top() != x) {
				pushad(p + 1, stacks[p].top());
				stacks[p].pop();
			}
			b.push_back(x);
			stacks[p].pop();
			show();
		}
		x++;
	}

}

int main() {

	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);

	show();

	stacksort();

	return 0;
}
