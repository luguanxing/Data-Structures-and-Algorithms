# LCS算法

<br><br>

### LCS的定义
```
最长公共子序列，即Longest Common Subsequence，LCS。
	一个序列S任意删除若干个字符得到新序列T，则T叫做S的子序列；
	两个序列X和Y的公共子序列中，长度最长的那个，定义为X和Y的最长公共子序列。
	字符串13455与245576的最长公共子序列为455
	字符串acdfg与adfc的最长公共子序列为adf
注意区别最长公共子串(Longest Common Substring)
	最长公共字串要求连续
```

<br><br>

### LCS的应用
```
(1)求两个序列中最长的公共子序列算法，广泛的应用在图形相似处理、媒体流的相似比较、
	计算生物学方面。生物学家常常利用该算法进行基因序列比对，由此推测序列的结构、功能和演化过程。
(2)LCS可以描述两段文字之间的“相似度”，即它们的雷同程度，从而能够用来辨别抄袭。
	另一方面，对一段文字进行修改之后，计算改动前后文字的最长公共子序列，将除此子序列外的部分提取
	出来，这种方法判断修改的部分，往往十分准确。简而言之，百度知道、百度百科都用得上。
```


<br><br>

### LCS的解法
```
(1)暴力解法:
	X的一个子序列即下标序列{1, 2, …, m}的严格递增子序列，因此，X共有2m个不同子序列；
	同理，Y有2n个不同子序列，从而穷举搜索法最长子序列需要指数时间O(2m . 2n)；
(2)LCS解法:
	动态规划解法
```
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/01-LCS%E7%AE%97%E6%B3%95/lcs.jpg?raw=true)<br>

<br><br><br><br><br><br>

### LCS的实现
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/01-LCS%E7%AE%97%E6%B3%95/lcs1.jpg?raw=true)<br>
计算LCS长度

<br><br><br><br><br>
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/01-LCS%E7%AE%97%E6%B3%95/lcs2.jpg?raw=true)<br>
计算方向数组

<br><br><br><br><br><br>

### LCS的扩展
```
(1)计算最长递增子序列LIS:
	将该串排序后和自身求LCS
(2)计算最长子串:
	当Xm不等于Yn时长度设为0
```
<br><br><br><br><br><br>

### Java代码
```
	private int[][] lcs_length = null;
	private int[][] lcs_direction = null;
	private List<Integer> lcs_result = new ArrayList<Integer>();
	
	public void print(int[][] A) {
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[i].length; j++) {
				System.out.print(A[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public void LCS(int[] X, int[] Y) {
		int m = X.length;
		int n = Y.length;
		lcs_length = new int[m+1][n+1];
		lcs_direction = new int[m+1][n+1];
		for (int i = 0; i <= m; i++)
			lcs_length[i][0] = 0;
		for (int i = 0; i <= n; i++)
			lcs_length[0][i] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
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
		print(lcs_length);
		System.out.println();
		print(lcs_direction);
		System.out.println();
		followResultOfLCS(X, m, n);
		System.out.println();
		System.out.println(getReusltOfLCS());
		System.out.println();
		System.out.println(lengthOfLCS());
	}
	
	public void followResultOfLCS(int[] X, int m, int n) {
		if (m == 0 || n == 0)
			return;
		if (lcs_direction[m][n] == 1) {
			followResultOfLCS(X, m-1, n-1);
			lcs_result.add(X[m-1]);
		} else if (lcs_direction[m][n] == 2) {
			followResultOfLCS(X, m-1, n);
		} else if (lcs_direction[m][n] == 3) {
			followResultOfLCS(X, m, n-1);
		}
	}
	
	public List<Integer> getReusltOfLCS() {
		return lcs_result;
	}
	
	public int lengthOfLCS() {
		int max = 0;
		for (int i = 0; i < lcs_length.length; i++) {
			for (int j = 0; j < lcs_length[i].length; j++) {
				if (lcs_length[i][j] > max) {
					max = lcs_length[i][j];
				}
			}
		}
		return max;
	}
```

### C++代码
```
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
```
