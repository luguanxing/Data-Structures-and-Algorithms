#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 10
int n, t, i;
int w[MAX];
int flag;		//flag���ڱ�ʾ�Ƿ����
stack<int> st;		//ջst���ڱ��浱ǰ���


void find(int start_place, int new_t) {		//�������start_place��ʼ���Ѱ�ң���ʱ����Ϊnew_t
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

void readin() {		//��������
	cout << "Input the number of things n: ";
	cin >> n;
	cout << "Input the volum of the package t: ";
	cin >> t;
	for(i = 0; i < n; i++) {
		cout << "Input the volum of each thing t[" << i+1 << "]: ";
		cin >> w[i];
	}
}

void find_and_out() {		//����������ʹ����пɶ��ԣ�ͬʱ���еݹ����
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
