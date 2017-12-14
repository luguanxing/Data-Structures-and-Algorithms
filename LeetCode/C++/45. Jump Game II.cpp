#include <iostream>
#include <math.h>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int minStep = 0;
		int nextTarget = 0;
		int nextNextTarget = 0;
		int len = nums.size();
		for (int step = 0; step < len;) {
			if (nextTarget >= len -1)
				return minStep;
			//计算下步过程中准备下下步
			while (step <= nextTarget) {
				nextNextTarget = max(nextNextTarget, step+nums[step]);
				step++;
			}
			nextTarget = nextNextTarget;
			minStep++;
		}
		return minStep;
    }
};                     

int main() {
	Solution so;
	vector<int> A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(1);
	A.push_back(1);
	A.push_back(4);
	cout << so.jump(A) << endl;
	return 0;
}