package medium;

import java.util.HashMap;
import java.util.Map;

public class Longest_Substring_Without_Repeating_Characters {

    public int lengthOfLongestSubstring(String s) {
    	//滑动窗口[left, right],探测s[++right]是否与窗口中字符重复,未重复right右移否则left左移至不重复
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
	
	public static void main(String[] args) {
		System.out.println(new Longest_Substring_Without_Repeating_Characters().lengthOfLongestSubstring("ibazc"));
	}

}
