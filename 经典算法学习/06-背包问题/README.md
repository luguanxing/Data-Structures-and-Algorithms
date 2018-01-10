# 背包问题

<br>

### 背包问题的定义
```
在不超过背包承重(容量)的前提下，选择的物品价值总和最大
```

### 0-1背包问题
```
问题:	
	每个物品可以取(任意比例)一部分，按照取的比例获得相应比例的价值 (比例在0-1之间)
解决:	
	使用贪心算法
	按照“性价比”排序，优先选取“性价比”较高的
```

### 0/1背包问题
```
问题:	
	每个物品要么全部取走，要么完全不取
解决:	
	假设每种物品的价值是v(i), 重量是w(i)，下标编号1-n， 背包承重是W,
	令A(n, W)计算最优决策下的物品总价值
	对于第n号物品:
		要么不拿它只考虑其前面的物品
		要么拿它并从剩下容量中考虑其它物品
	状态方程A(n, W) = max(A(n – 1, W), A(n – 1, W – w(n)) + v(n))
	初始状态即只考虑第一个物品A(0, i) = W(i);
```
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/06-%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98/packeting.jpg?raw=true)
<br><br><br><br><br><br><br>

### Java代码
```
public int packeting(int[] w, int[]v, int c) {
	int n = w.length;
	if ( n == 0)
		return 0;
	int[][] maxValue = new int[n][c+1];
	for (int j = 0; j <= c; j++)
		maxValue[0][j] = (j >= w[0] ? v[0] : 0);
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= c; j++) {
			//不拿第i件物品时
			int noTakeItemI = maxValue[i-1][j];
			maxValue[i][j] = noTakeItemI;
			if (j >= w[i]) {
				//能拿且拿第i件物品时
				int takeItemI = maxValue[i-1][j - w[i]] + v[i];
				maxValue[i][j] = Math.max(maxValue[i][j], takeItemI);
			}
		}
	return maxValue[n-1][c];
}
```

### C++代码
```
class Solution {
public:
	int packeting(const vector<int> &w, const vector<int> &v, int c) {
		int n = w.size();
		if ( n == 0)
			return 0;
		vector<vector<int>>  maxValue(n, vector<int>(c+1,-1));
		for (int j = 0; j <= c; j++)
			maxValue[0][j] = (j >= w[0] ? v[0] : 0);
		for (int i = 1; i < n; i++)
			for (int j = 0; j <= c; j++) {
				int noTakeItemI = maxValue[i-1][j];
				maxValue[i][j] = noTakeItemI;
				if (j >= w[i]) {
					int takeItemI = maxValue[i-1][j - w[i]] + v[i];
					maxValue[i][j] = max(maxValue[i][j], takeItemI);
				}
			}
		return maxValue[n-1][c];
	}
};

int main() {
	Solution so;
	int weights[] = {1,2,3};
	int values[] ={6, 10, 12};
	int capacity = 5;
	vector<int> w(weights, weights+3);
	vector<int> v(values, values+3);
	int c = capacity;
	cout << so.packeting(w, v, c) << endl;
	return 0;
}

```
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/06-%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98/exapmple.jpg?raw=true)

