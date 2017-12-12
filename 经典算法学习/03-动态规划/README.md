# 动态规划算法

<br><br>

### 动态规划的定义
```
	动态规划 (dynamic programming)是在状态集合上的递推
	f(new state) = f(old state) + payoff(decision)
```

<br><br>

### 基本概念
```
	一个系统，有若干状态，每个状态下有若干合法的操作,称为决策,决策会改变系统状态
	决策会带来收益（或费用）
	在初始状态下，求最终状态下最大收益
	在每个阶段，选择一些决策，状态随之改变
	收益只取决与当前状态和决策——不是马尔可夫
	使得系统达到终止状态时，总收益最大（或费用最小）
	总收益一般指各阶段收益的总和
```


<br><br>

### 动态规划的解法
```
	特点:
		子问题有大量重叠
	应对:
		打表避免重复计算
		表格记录每个状态的最大收益
	步骤
		确定状态集合和收益
		初始状态、终止状态
		确定决策集合
		是否无后效
		收益如何表示
```

<br><br><br><br><br><br>

### 精选例题1-最长单增子序列LIS
```
问题:	
	Longest Increasing Subsequence (LIS)最长单增子序列 给定一个数列，求它的最长单增的子序列
	例如 给定10,4,20,10,15,13 则{4,10,15}和{4,10,13}都是解
解决:	
	确定状态: 
		收益和状态 以第i项结尾的最长单增子序列的长度f(i)
		初始状态f(0) = 0
		终止状态max{f(1),f(2),f(3)…f(n)}
	决策: 
		已知全部f(x),  x < i，如果ai>ax，则显然可以把ai连接在ax的后面。
	无后效性:
		f(i)只与决策x相关
	收益表示: 
		由定义f(i) = max{f(x)| x < i且ai>ax｝ ＋ 1， 如果该集合是空集，则对应max值为0。
分析:
	时间复杂度: 
		枚举i
		枚举x,找到最大的满足条件的x
		O(n^2)
	空间复杂度: 
		存储每个f(i)*O(n)
	如何得到解: 
		记录决策:对每个f(i)记录得到它的前驱决策x

```

<br><br><br><br><br>

### 精选例题2-换硬币
```
问题:	
	用面值为C1,C2,C3……Cn的硬币，每种硬币面值数量不限，凑一定数量的钱，使得用硬币个数最少。
解决:	
	确定状态: 
		收益和状态 设第i元最少需要硬币数为f(i)
		初始状态f(0) = 0
		终止状态f(x)
	决策: 
		逐个向前找f(x-ci),找出最小的f(x-ci)在即x-ci配上ci可得x元，共f(x-ci)+1枚硬币。
	无后效性:
		f(x)只与决策x-ci相关
	收益表示: 
		f(x)=min{f(x-ci)}+1   i=1,2,3…n
分析:
	时间复杂度: 
		枚举ci
		O(n)
	如何得到解: 
		记录决策:对每个f(x)记录得到它的前驱决策x

```

<br><br><br><br><br>

### Java代码
```
	private int state[];
    public int coinChange(int[] coins, int amount) {
    	state = new int[amount+1];
    	state[0] = 0;
    	for (int i = 1; i <= amount; i++) {	//不断向后计算state[i]直到state[amount]
    		Set<Integer> set = new TreeSet();
    		for (int coin : coins) {
				if (i - coin < 0)
					continue;
				if (state[i - coin] != -1)
					set.add(state[i - coin]);
			}
    		if (set.isEmpty()) {
    			state[i] = -1;
    		} else {
    			Iterator<Integer> it = set.iterator();
    			if (it.hasNext())
    				state[i] = it.next() + 1;
    		}
    	}
    	for (int i = 0; i <= amount; i++)
    		System.out.print(state[i] + " ");
    	System.out.println();
        return state[amount];
    }
```

### C++代码
```
#define MAX 10005
class Solution {
	private:
		int state[MAX];
	public:
		int coinChange(vector<int>& coins, int amount) {
			state[0] = 0;
			for (int i = 1; i <= amount; i++) {		//²»¶ÏÏòºó¼ÆËãstate[i]Ö±µ½state[amount]
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
```
