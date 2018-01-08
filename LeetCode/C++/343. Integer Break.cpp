#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
		//动态规划计算最大积，leetcode上使用new分配会出错
		vector<int> maxProduct(100, 0);
		maxProduct[1] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= i-1; j++)
				maxProduct[i] = max( maxProduct[i],  max(j*(i-j), j*maxProduct[i-j]) );
		return maxProduct[n];
    }
};

int main() {
	Solution so;
	cout << so.integerBreak(10) << endl;
	return 0;
}