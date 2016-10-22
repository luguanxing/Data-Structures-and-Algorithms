/*
Description
猴子选大王，有N只猴子，从1～N进行编号。它们按照编号的顺时针方向，排成一个圆圈，然后从第一只猴子开始报数。第一只猴子报1，以后每只猴子报的数字都是它前面猴子所报数字加1。如果一只猴子报的数字是M，则该猴子出列，下一只猴子重新从1开始报数。剩下的猴子继续排成一个圆圈报数，直到全部的猴子都出列为止。最后一个出列的猴子胜出。
 

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