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
    int rob(vector<int>& nums) {
        //设maxValue[x]表示考虑[0-x]最大的价值
    	//对于任意nums[i]>0状态方程f(x)=max{f(x-2)+nums[x], f(x-1)}
    	int* maxValue = new int[nums.size()+1];
    	maxValue[0] = 0;
    	for (int i = 1; i <= nums.size(); i++) {
    		if (i - 2 >= 0) {
    			int robI = maxValue[i-2] + nums[i-1];
    			int noRobi = maxValue[i-1];
    			maxValue[i] = max(robI, noRobi);
    		} else {
    			maxValue[i] = nums[0];
    		}
    	}
		return maxValue[nums.size()];
    }
};

int main() {
	Solution so;
	int a[] = {8,3,6,15,4,9,7,10};
	vector<int> nums(a, a+8);
	cout << so.rob(nums) << endl;
	return 0;
}