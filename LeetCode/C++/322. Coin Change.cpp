#include <iostream>
#include <math.h>
#include <vector>
#include<algorithm>
using namespace std;

#define MAX 10005
class Solution {
	private:
		int state[MAX];
	public:
		int coinChange(vector<int>& coins, int amount) {
			state[0] = 0;
			for (int i = 1; i <= amount; i++) {		//不断向后计算state[i]直到state[amount]
				vector<int> v;
				for (int j = 0; j < coins.size(); j++) {	//state[i]=min{state(x-Ci)}+1
					if (i - coins[j] < 0)
						continue;
					if (state[i - coins[j]] != -1)
						v.push_back(state[i - coins[j]]);
				}
				sort(v.begin(), v.end());
				if (v.empty()) {
					state[i] = -1;
				} else {
					state[i] = v[0] + 1;
				}
			}
			for (int i = 0; i <= amount; i++)
				cout << state[i] << " ";
			cout << endl;
			return state[amount];
		}
};                                 

int main() {
	Solution so;
	int amount = 100;
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	cout << "f(" << amount << ")=" << so.coinChange(coins, amount) << endl;
	return 0;
}