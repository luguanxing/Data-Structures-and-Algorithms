package easy;

public class Implement_strStr {

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
    
    public static void main(String[] args) {
    	Implement_strStr main = new Implement_strStr();
    	String haystack = "mississippi";
    	String needle = "issip";
    	System.out.println(main.strStr(haystack, needle));
	}
	
}
