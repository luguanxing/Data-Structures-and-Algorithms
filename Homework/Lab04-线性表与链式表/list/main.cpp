#include <iostream>
using namespace std;
#define MAX 5


template <typename T>
struct node {
	T data;
	node<T> *next;
	node(T x = 0, node<T>* y = NULL):data(x), next(y) {}
};

template <typename T>
class Array {
	public:
		node<T>* head;		//headΪͷ���
		int size;		//sizeΪ��ǰ�ڵ�����
		Array();
		bool insert(int place, T x);
		bool remove(int place);
		void output();
};

template <typename T>
Array<T>::Array() {
	head = NULL;
	size = 0;
}

template <typename T>
bool Array<T>::insert(int place, T x) {
	if (place < 0 || place > size+1)		//placeҪ����0-size+1֮�䣬�Ҳ������
		return false;
	if (place == 0) {
		node<T>* newhead = new node<T>(x, head);
		head = newhead;
	} else {
		node<T> *p = head;
		for (int ct = 1; ct <= place-1; ct++)
			p = p->next;
		node<T> *p2 = new node<T>(x, p->next);
		p->next = p2;
	}
	size++;
	return true;
}

template <typename T>
bool Array<T>::remove(int place) {
	if (place < 0 || place > size)		//placeҪ����0-size֮�䣬�Ҳ���ɾ���ձ�
		return false;
	if (place == 0) {
		node<T>* nowhead = head;
		node<T>* newhead = head->next;
		delete nowhead;
		head = newhead;
	} else {
		node<T> *p = head;
		for (int ct = 1; ct <= place-1; ct++)
			p = p->next;
		node<T> *target = p->next;
		node<T> *p2 = p->next->next;
		p->next = p2;
		delete target;
	}
	size--;
	return true;
}

template <typename T>
void Array<T>::output() {
	node<T> *p = head;
	while(p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	int i;
	Array<char> a;
	char computer[] = "COMPUTER";
	for(i = 0; i < 8; i++)
		cout << ((a.insert(0, computer[i]) == true) ? "YES" : "NO") << endl;
	a.output();

	Array<char> b;
	for(i = 0; i < 8; i++)
		cout << ((b.insert(i, computer[i]) == true) ? "YES" : "NO") << endl;
	b.output();

	return 0;
}