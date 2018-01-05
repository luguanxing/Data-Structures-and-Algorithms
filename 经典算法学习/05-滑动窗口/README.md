# ��������

<br><br>

### �������ڵĶ���
```
	����������ָ���������������������������ָ�뻬������������ض�����ֵ��
```

### ����-Longest Substring Without Repeating Characters
```
����:	
	��һ���ַ������ҳ����û���ظ��ַ������ַ���
���:	
	ά�ֻ�������[left, right]
	ά�ִ����ظ���new HashMap<Character, Boolean>()��flag[256]={false}
	̽��s[++right]�Ƿ��봰�����ַ��ظ�
		δ�ظ�right����
		��left����֪�������ڲ��ظ�
```

<br><br><br><br><br>

### Java����
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

### C++����
```
    int lengthOfLongestSubstring(string s) {
		//��������[left, right],̽��s[++right]�Ƿ��봰�����ַ��ظ�,δ�ظ�right���Ʒ���left���������ظ�
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
