package easy;

public class Repeated_Substring_Pattern {

	// subLen从长度为1到len/2进行子段暴力匹配
	class Solution {
	    public boolean repeatedSubstringPattern(String s) {
	    	int len = s.length();
	    	for (int subLen = 1; subLen <= len / 2; subLen++) {
	    		if (len % subLen == 0) {
	    			String subStr = s.substring(0, subLen);
	    			int subSegsLen = len / subLen;
	    			boolean flag = true;
	    			// 向后匹配长subLen的子段看是否相同
	    			for (int curSeg = 1; curSeg < subSegsLen; curSeg++) {
	    				if (!s.substring(curSeg * subLen, (curSeg + 1) * subLen).equals(subStr)) {
	    					flag = false;
	    					break;
	    				}
	    			}
	    			if (flag) {
	    				return true;
	    			}
	    		} else {
	    			continue;
	    		}
	    	}
	        return false;
	    }

	    // 另一个方法,加上自己后从1开始找自己，看能否在自身长度前找到,如abab得到ab[abab]ab
	    public boolean _repeatedSubstringPattern(String s) {
	        int len = s.length();
	        if (len < 2) {
	            return false;
	        }
	        return (s+s).indexOf(s, 1) < len;
	    }
	}
	
	public static void main(String[] args) {
		String s = "abcabcabcabc";
		System.out.println(new Repeated_Substring_Pattern().new Solution().repeatedSubstringPattern(s));
	}
	
}
