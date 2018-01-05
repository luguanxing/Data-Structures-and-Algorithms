#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		//滑动窗口[left, right],探测s[++right]是否与窗口中字符重复,未重复right右移否则left左移至不重复
		int len = s.size();
		int left = 0, right = -1;
		int maxLen = 0;
		bool flag[256] = {false};
		while (left < len) {
			if (right + 1 < len && flag[s[right + 1]] == false) {
				flag[s[++right]] = true;
			} else {
				flag[s[left++]] = false;
			}
			maxLen = max(maxLen, right - left + 1);
		}
		return maxLen;
    }
};

int main() {
	Solution so;
	cout << so.lengthOfLongestSubstring("") << endl;
	return 0;
}