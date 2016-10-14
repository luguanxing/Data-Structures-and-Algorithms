#include <iostream>
using namespace std;
#define MAX 5


template <typename T>
class Array {
	public:
		T array[MAX];		//array[0-MAX]Ϊ������
		int num;		//num==-1Ϊ������
		Array();
		bool insert(int place, T x);
		bool remove(int place);
		void output();
};

template <typename T>
Array<T>::Array() {
	memset(array, 0, MAX);
	num = -1;
}

template <typename T>
bool Array<T>::insert(int place, T x) {
	if (place < 0 || place > num+1 || num+1 >= MAX)		//placeҪ����0-num+1֮�䣬�Ҳ������
		return false;
	for(int i = num; i >= place; i--)
		array[i+1] = array[i];
	array[place] = x;
	num++;
	return true;
}

template <typename T>
bool Array<T>::remove(int place) {
	if (place < 0 || place > num || num == -1)		//placeҪ����0-num֮�䣬�Ҳ���ɾ���ձ�
		return false;
	for(int i = place; i < num; i++)
		array[i] = array[i+1];
	array[num] = 0;
	num--;
	return true;
}

template <typename T>
void Array<T>::output() {
	for (int i = 0; i <= num; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	int i;
	Array<char> a;	//MAX = 5
	char computer[] = "COMPUTER";
	for (i = 0; i < 8; i++)
		cout << ((a.insert(0, computer[i]) == true) ? "YES" : "NO") << endl;
	a.output();
	Array<char> b;
	for (i = 0; i < 8; i++)
		cout << ((b.insert(i, computer[i]) == true) ? "YES" : "NO") << endl;
	b.output();
	return 0;
}