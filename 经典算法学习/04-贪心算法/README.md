# 贪心算法

<br><br>

### 贪心算法的定义
```
	贪心算法(greedy algorithm)是指，在对问题求解时，总是做出在当前看来是最好的选择。
```

<br><br>

### 基本概念
```
	可选对象全集S
	已经选择对象的集合T （部分解）
	一个判断解合法函数 isValid(T)
	一个评价解的函数 payoff(T)
	目标：
		从S中选择出一个子集T,使得子集合法isValid(T) == true 并且使得payoff(T)最大
	算法：
		从空集开始，每次加一个元素使得总payoff尽可能大—— 贪心选择性质的证明
```


<br><br>

### 贪心算法和动态规划
```
	贪心算法的递推式
		opt(x) = opt(y) + max｛ payoff(y, x)｝
		y是“固定”的,选择收益最大的，变成状态x
		x取决于y
	动态规划的递推式
		opt(x) = max{opt(y) + payoff(y, x)}
		y是能到达x的所有可能的状态
		x是“固定”的，y是变量取决于x
		payoff(y,x)是从状态y到状态x的收益
```

<br><br><br><br><br><br>

### 例题1-换零钱
```
问题:	
	用1，2，5的硬币凑出n，使得所用的币数最少
解决:	
	贪心方法，先尽可能用5凑，然后用2， 然后用1。
	证明： 
		分情况讨论n=5k, 5k+1,5k+2,5k+3,5k+4
		k=0可以枚举全部解，正确
		如果k=m贪心成立，那么k=m+1时 (m >= 0)时
		例如n=5(m+1)的时候，利用“动态规划”的式子计算最优解
		5(m + 1) – 1 多用1个1 ， 那么变为5m + 4的解，多用1个1，由归纳假设需要m + 3个硬币
		5(m + 1) – 2 多用1个2， 那么变为5m + 3的解，多用1个2， 由归纳假设需要m + 3个硬币
		5(m + 1) – 5 多用1个5， 那么变为5m的解，多用1个5， 由归纳假设需要m + 1个硬币。
		类似可以证明5(m + 1) + 2, +3, +4的情况
	注意：不是所有硬币集合都可以贪心。例如{1,2,5,7}凑10
```

<br><br><br><br><br>

### 例题2-活动安排问题
```
问题:	
	有若干个活动，第i个开始时间和结束时间是[Si,fi)，只有一个教室，活动之间不能交叠，求最多安排多少个活动？
解决:	
	贪心原则：
		按照结束时间排序，找所有不冲突的。
	简证：
		有一个其他的最优解，我们把其中的活动也按照结束时间排序，我们可以把其中的任务一个一个换成我们贪心的任务，而不造成冲突。
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
