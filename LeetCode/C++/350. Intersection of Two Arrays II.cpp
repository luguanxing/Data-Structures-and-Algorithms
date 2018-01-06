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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map;
		vector<int> result;
		for (int i = 0; i < nums1.size(); i++)
			map[nums1[i]]++;
		for (int i = 0; i < nums2.size(); i++)
			if (map[nums2[i]] > 0) {
				map[nums2[i]]--;
				result.push_back(nums2[i]);
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
	vector<int> res = so.intersect(nums1, nums2);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}