# 滑动窗口

<br><br>

### 滑动窗口的定义
```
	滑动窗口是指，在求解数组问题中用左右两个指针滑动来求出数组特定计算值。
```

### 例题-Longest Substring Without Repeating Characters
```
问题:	
	有一个字符串，找出最长的没有重复字符的子字符串
解决:	
	维持滑动窗口[left, right]
	维持窗口重复集new HashMap<Character, Boolean>()或flag[256]={false}
	探测s[++right]是否与窗口中字符重复
		未重复right右移
		复left左移知道窗口内不重复
```

<br><br><br><br><br>

### Java代码
```
    public int lengthOfLongestSubstring(String s) {
    	int len = s.length();
        Map<Character, Boolean> flag = new HashMap<Character, Boolean>();
    	int left = 0;
        int right = -1;
    	int maxLen = 0;
    	while (left < len) {
    		if (right + 1 < len && flag.get(s.charAt(right+1)) == null)
    			flag.put(s.charAt(right+1), false);
    		if (right + 1 < len && !flag.get(s.charAt(right+1))) {
    			flag.put(s.charAt(++right), true);
    		} else {
    			flag.put(s.charAt(left++), false);
			}
    		maxLen = Math.max(maxLen, right - left + 1);
    	}
    	return maxLen;
    }
```

### C++代码
```
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
```
