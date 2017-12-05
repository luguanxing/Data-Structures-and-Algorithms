#include "stdio.h"  
#include "stdlib.h"
#include <string.h>  
#include <math.h>  
#include <iostream> 
#include <algorithm>  
#include <vector>  
using namespace std;
#define MAX 10005

int lcs_length[MAX][MAX];
int lcs_direction[MAX][MAX];

class Solution {
public:
	int m, n;
	vector<int> lcs_result;

	void print(int A[MAX][MAX], int y, int x) {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
	}

	void LCS(int X[] , int Y[], int m, int n) {
		this->m = m;
		this->n = n;
		for (int i = 0; i <= m; i++) {
			lcs_length[i][0] = 0;
			lcs_direction[i][0] = 0;
		}
		for (int i = 0; i <= n; i++) {
			lcs_length[0][i] = 0;
			lcs_direction[0][i] = 0;
		}
		for (int i =1; i <= m; i++) {
			for (int j =1; j <= m; j++) {
				if (X[i-1] == Y[j-1]) {
					lcs_length[i][j] = lcs_length[i-1][j-1] + 1;
					lcs_direction[i][j] = 1;
				} else if (lcs_length[i-1][j] >= lcs_length[i][j-1]) {
					lcs_length[i][j] = lcs_length[i-1][j];
					lcs_direction[i][j] = 2;
				} else {
					lcs_length[i][j] = lcs_length[i][j-1];
					lcs_direction[i][j] = 3;
				}
			}
		}
		print(lcs_length, m+1, n+1);
		cout << endl;
		print(lcs_direction, m+1, n+1);
		cout << endl;
		followResultOfLCS(X, m, n);
		for (int i = 0; i < lcs_result.size(); i++)
			cout << lcs_result[i] << " ";
		cout << endl;
	}

	void followResultOfLCS(int X[], int m, int n) {
		if (m == 0 || n == 0)
			return;
		if (lcs_direction[m][n] == 1) {
			followResultOfLCS(X, m-1, n-1);
			lcs_result.push_back(X[m-1]);
		} else if (lcs_direction[m][n] == 2) {
			followResultOfLCS(X, m-1, n);
		} else if (lcs_direction[m][n] == 3) {
			followResultOfLCS(X, m, n-1);
		}
	}

    int lengthOfLCS() {
		return lcs_result.size();
    }

    int lengthOfLIS(vector<int>& nums) {
		int m = nums.size();
		int * nums1 = new int[m];
		for (int i = 0; i < m; i++)
			nums1[i] = nums[i];
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		int n =nums.size();
		int * nums2 = new int[n];
		for (int i = 0; i < n; i++)
			nums2[i] = nums[i];
		LCS(nums1, nums2, m, n);
		return lengthOfLCS();
    }
};

int main(void)  
{  
	Solution so;
	int a[MAX] = {};
	vector<int> v;
	for (int i = 0; i < 0; i++)
		v.push_back(a[i]);
	cout << so.lengthOfLIS(v) << endl;
}  