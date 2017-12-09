# KMP算法

<br><br>

### KMP的定义
```
	给定文文本串text和模式串pattern，要求从文本串text中找出模式串pattern首次出现位置
```

<br><br>

### KMP的应用
```
	匹配字符串,DNA等
```


<br><br>

### 字符串匹配的解法
```
	(1)暴力解法:
		对于文本串text逐个匹配模式串pattern匹配成功则继续，失败则将模式串pattern右移一位
	(2)KMP解法:
		对于文本串text逐个匹配模式串pattern匹配成功则继续，失败则将模式串利用next右移至少一位
```
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/02-KMP%E7%AE%97%E6%B3%95/kmp1.jpg?raw=true)

<br><br><br><br><br><br>

### KMP的思想和实现
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/02-KMP%E7%AE%97%E6%B3%95/kmp2.jpg?raw=true)<br>
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/02-KMP%E7%AE%97%E6%B3%95/kmp3.jpg?raw=true)<br>
![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/02-KMP%E7%AE%97%E6%B3%95/kmp4.jpg?raw=true)<br>
计算next数组

<br><br><br><br><br>

![img](https://github.com/luguanxing/Data-Structures-and-Algorithms/blob/master/%E7%BB%8F%E5%85%B8%E7%AE%97%E6%B3%95%E5%AD%A6%E4%B9%A0/02-KMP%E7%AE%97%E6%B3%95/kmp5.jpg?raw=true)<br>
利用next数组计算KMP
<br><br><br><br><br><br>

### KMP的扩展
```
	//不匹配时先判断是否和上次相同,是的话利用上次结论
	if (pattern[j] == pattern[k]) {
		next[j] = next[k];
	} else {
		next[j] = k;
	}
```
<br><br><br><br><br><br>

### Java代码
```
	int next[] = null;
	String text = null;
	String pattern = null;
	
	public void calcNext() {
		next = new int[pattern.length()];
		next[0] = -1;
		int k = -1;
		int j = 0;
		while (j < pattern.length()-1) {
			if (k==-1 || pattern.charAt(j)==pattern.charAt(k)) {
				//初始化或相等时均右移
				k++;
				j++;
				next[j] = k;
			} else {
				//不匹配,继续向前递归
				k = next[k];
			}
		}
	}
	
	public void calcNextEx() {
		next = new int[pattern.length()];
		next[0] = -1;
		int k = -1;
		int j = 0;
		while (j < pattern.length()-1) {
			if (k==-1 || pattern.charAt(j)==pattern.charAt(k)) {
				//初始化或相等时均右移
				k++;
				j++;
				//改良版先判断是否和上次相同
				if (pattern.charAt(j) == pattern.charAt(k)) {
					next[j] = next[k];
				} else {
					next[j] = k;
				}
			} else {
				//不匹配,继续向前递归
				k = next[k];
			}
		}
	}
	
	public int KMP() {
		this.calcNextEx();
		int ans = -1;
		int i = 0;
		int j = 0;
		int text_len = text.length();
		int pattern_len = pattern.length();
		while (i < text_len) {
			if (j==-1 || text.charAt(i)==pattern.charAt(j)) {
				//初始化或主串和子串匹配上了
				i++;
				j++;
			} else {
				//子串不匹配则滑动
				j = next[j];
			}
			if (j == pattern_len) {
				ans = i - pattern.length();
				break;
			}
		}
		return ans;
	}
	
    public int strStr(String haystack, String needle) {
        text = haystack;
        pattern = needle;
        if (needle.isEmpty())
        	return 0;
        if (haystack.isEmpty())
        	return -1;
    	return this.KMP();
    }
```

### C++代码
```
#define MAX  10005

class Solution {
	private:
		int next[MAX];
		string text;
		string pattern;
	public:
		void calcNext() {
			next[0] = -1;
			int k = -1;
			int j = 0;
			while (j < pattern.length()-1) {
				if (k==-1 || pattern[j]==pattern[k]) {
					//初始化或相等时均右移
					k++;
					j++;
					next[j] = k;
				} else {
					//不匹配,继续向前递归
					k = next[k];
				}
			}
		}

		void calcNextEx() {
			next[0] = -1;
			int k = -1;
			int j = 0;
			while (j < pattern.length()-1) {
				if (k==-1 || pattern[j]==pattern[k]) {
					//初始化或相等时均右移
					k++;
					j++;
					//改良版先判断是否和上次相同
					if (pattern[j] == pattern[k]) {
						next[j] = next[k];
					} else {
						next[j] = k;
					}
				} else {
					//不匹配,继续向前递归
					k = next[k];
				}
			}
		}

		int KMP() {
			this->calcNextEx();
			int ans = -1;
			int i = 0;
			int j = 0;
			int text_len = text.length();
			int pattern_len = pattern.length();
			while (i < text_len) {
				if (j==-1 || text[i]==pattern[j]) {
					//初始化或主串和子串匹配上了
					i++;
					j++;
				} else {
					//子串不匹配则滑动
					j = next[j];
				}
				if (j == pattern_len) {
					ans = i - pattern.length();
					break;
				}
			}
			return ans;
		}

		int strStr(string haystack, string needle) {
			text = haystack;
			pattern = needle;
			if (needle.empty())
        		return 0;
			if (haystack.empty())
        		return -1;
    		return this->KMP();
		}
};
```
