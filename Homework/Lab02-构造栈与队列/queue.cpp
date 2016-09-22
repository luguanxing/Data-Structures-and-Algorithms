#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define MAX 500

template<typename T>
class queue {
	public:
		T s[MAX + 1];
		int ct;
		int head;
		int rear;
		queue();
		void push(T x);
		void pop();
		T front();
		T back();
		bool empty();
		bool full();
		void clear();
};

template<typename T>
queue<T>::queue<T>() {
	ct = 0;
	head = rear = 0;
	clear();
}

template<typename T>
bool queue<T>::empty() {
	return head == rear;
}

template<typename T>
bool queue<T>::full() {
	return (rear+1) % MAX == head;
}

template<typename T>
void queue<T>::clear() {
	for (int i = 0; i < MAX; i++)
		s[i] = 0;
	head = rear = 0;
}

template<typename T>
void queue<T>::push(T x) {
	if (full())
		return;
	s[rear] = x;
	rear = (rear + 1) % MAX;
}

template<typename T>
void queue<T>::pop() {
	if (empty())
		return;
	head = (head + 1) % MAX;
}

template<typename T>
T queue<T>::front() {
	if (empty())
		return 0;
	return s[head];
}

template<typename T>
T queue<T>::back() {
	if (empty())
		return 0;
	return s[(rear-1+MAX)%MAX];
}

int main() {

	queue<char> cqu;
	queue<int> iqu;
	queue<float> fqu;

	cout << "choose queue\n1-int\n2-char\n3-float\n";
	int type;
	cin >> type;

	cout << "choose function:\n\"push x\"\n\"pop x\"\n\"front\"\n\"back\"\n\"clear\"\n\"empty\"\n\"full\"\n";
	while(true) {
		if (type == 1) {
			int i;
			string cmd;
			cin >> cmd;
			if (cmd == "push") {
				cin >> i;
				iqu.push(i);
			} else if (cmd == "pop") {
				iqu.pop();
			} else if (cmd == "front") {
				cout << iqu.front() << endl;
			} else if (cmd == "back") {
				cout << iqu.back() << endl;
			}  else if (cmd == "clear") {
				iqu.clear();
			} else if (cmd == "empty") {
				if (iqu.empty())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else if (cmd == "full") {
				if (iqu.full())
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
				cqu.push(c);
			} else if (cmd == "pop") {
				cqu.pop();
			} else if (cmd == "front") {
				cout << cqu.front() << endl;
			} else if (cmd == "back") {
				cout << cqu.back() << endl;
			}  else if (cmd == "clear") {
				cqu.clear();
			} else if (cmd == "empty") {
				if (cqu.empty())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else if (cmd == "full") {
				if (cqu.full())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else
				cout << "Unkown command!\n" << endl;
		} else if (type == 3) {
			float f;
			string cmd;
			cin >> cmd;
			if (cmd == "push") {
				cin >> f;
				fqu.push(f);
			} else if (cmd == "pop") {
				fqu.pop();
			} else if (cmd == "front") {
				cout << fqu.front() << endl;
			} else if (cmd == "back") {
				cout << fqu.back() << endl;
			}  else if (cmd == "clear") {
				fqu.clear();
			} else if (cmd == "empty") {
				if (fqu.empty())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			} else if (cmd == "full") {
				if (fqu.full())
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


