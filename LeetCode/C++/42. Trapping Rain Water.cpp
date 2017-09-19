#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
		int trap(vector<int>& heights) {
			if (heights.size() == 0)
				return 0;
    		int waterSum = 0;
    		int maxHeight = heights[0];
    		int maxIndex = 0;

			for (int x = 0; x < heights.size(); x++) {
        		int height = heights[x];
				if (height > maxHeight) {
					maxHeight = height;
					maxIndex = x;
				}
			}

			int leftMax = 0;
			for (int left = 0; left < maxIndex; left++) {
        		if (heights[left] > leftMax) {
        			leftMax = heights[left];
        		} else {
        			waterSum += leftMax - heights[left];
        		}
			}

			int rightMax = 0;
			for (int right = heights.size() - 1; right > maxIndex; right--) {
        		if (heights[right] > rightMax) {
        			rightMax = heights[right];
        		} else {
        			waterSum += rightMax - heights[right];
        		}
			}
        
    		return waterSum;
		}
};

int main() {
	Solution solution;
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(0);
	vi.push_back(2);
	cout << solution.trap(vi);
	return 0;
}