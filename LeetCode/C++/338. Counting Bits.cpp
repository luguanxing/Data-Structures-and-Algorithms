#include <iostream>
#include <math.h>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		vector<int> countBits(int num) {
			vector<int> result;
			result.push_back(0);
			if (num == 0)
				return result;
			result.push_back(1);
			//��k��¼�������
			int k = 0;
			//����bits[]
			for (int i = 2; i <= num; i++) {
				if ( !(i & (i-1))) {	//��2^k��λ��Ϊ1
					result.push_back(1);
					k++;
				} else {			//��2^k+x��λ��Ϊ1+bits[x]
					result.push_back(1 + result[i - (1 << k)]);
				}
			}
			return result;
		}
};          

int main() {
	Solution so;
	vector<int> v = so.countBits(15);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}