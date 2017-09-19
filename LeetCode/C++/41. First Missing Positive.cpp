#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			bool flags[1005] = {false};
			vector<int>::iterator it;
			for (it = nums.begin(); it != nums.end(); it++) {
				if (*it > 0)
					flags[*it] = true;
			}
			for (int i = 1; i < 1005; i++) {
				if (!flags[i])
					return i;
			}
		}
};

int main() {
	Solution solution;
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(0);
	vi.push_back(2);
	cout << solution.firstMissingPositive(vi);
	return 0;
}