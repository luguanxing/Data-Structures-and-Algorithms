/*
Description
����ѡ��������Nֻ���ӣ���1��N���б�š����ǰ��ձ�ŵ�˳ʱ�뷽���ų�һ��ԲȦ��Ȼ��ӵ�һֻ���ӿ�ʼ��������һֻ���ӱ�1���Ժ�ÿֻ���ӱ������ֶ�����ǰ������������ּ�1�����һֻ���ӱ���������M����ú��ӳ��У���һֻ�������´�1��ʼ������ʣ�µĺ��Ӽ����ų�һ��ԲȦ������ֱ��ȫ���ĺ��Ӷ�����Ϊֹ�����һ�����еĺ���ʤ����
 

Input
The first line is an integer t, indicating the number of test cases. Then there are t lines and each line contains two positive integer N(0<N<=1000) and M(0<M<=10000).

Output
For each test case, print out the number of the Monkey King.

Sample Input
 Copy sample input to clipboard
2
5 2
4 3
Sample Output
3
1
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		vector<int> v;
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			v.push_back(i);
		int p = 1;
		while (v.size() != 1) {
			vector<int>::iterator it = v.begin();
			while (v.size() > 1) {
				if (p == m) {
					it = v.erase(it);
					p = 1;
				} else {
					it++;
					p++;
				}
				if (it == v.end())
					break;
			}
		}
		cout << v[0] << endl;
	}
	return 0;
}