#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 10
int n, t, i;
int w[MAX];
int flag;		//flag用于表示是否存在
stack<int> st;		//栈st用于保存当前结果


void find(int start_place, int new_t) {		//从数组的start_place开始向后寻找，此时容量为new_t
	int status = new_t - w[start_place];
	if (status == 0) {
		flag = true;
		st.push(w[start_place]);
		stack<int> res = st;
		cout << "The probable answer: ";
		while (res.size()) {
			cout << res.top() << " ";
			res.pop();
		}
		cout << endl;
		st.pop();
	} else if (status > 0) {
		st.push(w[start_place]);
		for (int i = start_place + 1; i < n; i++)
			find(i, status);
		st.pop();
	} else if (status < 0) {
		return ;
	}
}

void readin() {		//读入数据
	cout << "Input the number of things n: ";
	cin >> n;
	cout << "Input the volum of the package t: ";
	cin >> t;
	for(i = 0; i < n; i++) {
		cout << "Input the volum of each thing t[" << i+1 << "]: ";
		cin >> w[i];
	}
}

void find_and_out() {		//对数据排序，使结果有可读性，同时进行递归查找
	sort(w, w+n);
	flag = false;
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < n; i++)
		find(i, t);
	if (!flag)
		cout << "can't find answer!" << endl;
	cout << "--------------------------------------" << endl;
}

int main() {	
	readin();
	find_and_out();
	return 0;
}
