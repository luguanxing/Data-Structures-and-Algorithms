#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
			return 0;
		int now = 0;
		int next = 1;
		for (int i = 0; i < n; i++) {
			int tmp = next;
			next += now;
			now = tmp;
		}
		return next;
    }
};

int main() {
	Solution so;
	cout << so.climbStairs(4) << endl;
	return 0;
}