/*
	Description
	����HASH��ʽ���������ͻ���ҹ涨����������ͷ������Ԫ�ء�

	�涨HASH����Ϊ��h(x) = x % 11������ϣ�����±�Ϊ0��10.

	�������ֲ�����

	��         I ����������һ���µ�������K����ϣ����

	��         F ��������ѯ����K�Ƿ��ڹ�ϣ���У������ڣ����-1�������ڣ����ĿǰK�����������е�˳���������ٶ�����ͷ����Ϊ0����

	Input
	 һ�����ݡ�

	��һ��Ϊ����N��0 < N <= 10000��

	������N��Ϊ������ֵ�I������F������(���ݱ�֤K�����ظ���KΪ����0��int����)

	Output
	 ����ÿ��F��������˳����������
*/
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> hash[1005];

int main() {
    int n, x, i, j;
    char c;
    cin >> n;
    while (n--) {
        cin >> c >> x;
        if (c == 'F') {
            if (find(hash[x%11].begin(), hash[x%11].end(), x) == hash[x%11].end())
                cout << "-1" << endl;
            else
                cout << find(hash[x%11].begin(), hash[x%11].end(), x) -  hash[x%11].begin() << endl;
        } else if (c == 'I') {
            hash[x%11].push_front(x);
        } else ;
    }
    return 0;
}                                        