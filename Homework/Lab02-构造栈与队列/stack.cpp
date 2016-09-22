#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX 500

template<typename T>
class stack {
	public:
		T s[MAX];
		int ct;
		stack();
		void push(T x);
		void pop();
		T top();
		bool empty();
		bool full();
		void clear();
};

template<typename T>
stack<T>::stack<T>() {
	ct = 0;
	clear();
}

template<typename T>
bool stack<T>::empty() {
	return ct == 0;
}

template<typename T>
bool stack<T>::full() {
	return ct == MAX;
}

template<typename T>
void stack<T>::clear() {
	for (int i = 0; i < MAX; i++)
		s[i] = 0;
	ct = 0;
}

template<typename T>
void stack<T>::push(T x) {
	if (full())
		return;
	s[ct++] = x;
}

template<typename T>
void stack<T>::pop() {
	if (empty())
		return;
	s[--ct] = 0;
}

template<typename T>
T stack<T>::top() {
	if (empty())
		return 0;
	return s[ct-1];
}

int main() {

	stack<char> cst;
	stack<int> ist;
	stack<float> fst;

	cout << "choose stack\n1-int\n2-char\n3-float\n";
	int type;
	cin >> type;

	


	cout << "choose function:\n\"push x\"\n\"pop x\"\n\"top\"\n\"clear\"\n\"empty\"\n\"full\"\n";
	while(true) {
		if (type == 1) {
			int i;
			string cmd;
			cin >> cmd;
			if (cmd == "push") {
				cin >> i;
				ist.push(i);
			} else if (cmd == "pop") {
				ist.pop();
			} else if (cmd == "top") {
				cout << ist.top() << endl;
			} else if (cmd == "clear") {
				ist.clear();
			} else if (cmd == "empty") {
				if (ist.empty())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else if (cmd == "full") {
				if (ist.full())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else
				cout << "Unkown command!\n" << endl;
		} else if (type == 2) {
			char c;
			string cmd;
			cin >> cmd;
			if (cmd == "push") {
				cin >> c;
				cst.push(c);
			} else if (cmd == "pop") {
				cst.pop();
			} else if (cmd == "top") {
				cout << cst.top() << endl;
			} else if (cmd == "clear") {
				cst.clear();
			} else if (cmd == "empty") {
				if (cst.empty())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else if (cmd == "full") {
				if (cst.full())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else
				cout << "Unkown command!\n" << endl;
		} else if (type == 3) {
			char f;
			string cmd;
			cin >> cmd;
			if (cmd == "push") {
				cin >> f;
				fst.push(f);
			} else if (cmd == "pop") {
				fst.pop();
			} else if (cmd == "top") {
				cout << fst.top() << endl;
			} else if (cmd == "clear") {
				fst.clear();
			} else if (cmd == "empty") {
				if (fst.empty())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else if (cmd == "full") {
				if (fst.full())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else
				cout << "Unkown command!\n" << endl;
		} else	
			cin >> type;

	}
	return 0;
}
