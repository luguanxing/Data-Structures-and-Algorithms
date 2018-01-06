#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> set1(nums1.begin(), nums1.end());
		set<int> set2(nums2.begin(), nums2.end());
		vector<int> result;
		for (set<int>::iterator it = set2.begin(); it != set2.end(); it++) {
			if (set1.find(*it) != set1.end())
				result.push_back(*it);
		}
		return result;
    }
};

int main() {
	Solution so;
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(2);
	nums1.push_back(1);
	nums2.push_back(2);
	nums2.push_back(2);
	vector<int> res = so.intersection(nums1, nums2);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}