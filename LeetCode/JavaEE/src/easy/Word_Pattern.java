package easy;

import java.util.HashMap;
import java.util.Map;

public class Word_Pattern {

	class Solution {
	    public boolean wordPattern(String pattern, String str) {
	        if (pattern == null || str == null) {
	        	return false;
	        }
	        String[] strs = str.split(" ");
	        if (pattern.length() != strs.length) {
	        	return false;
	        }
	        Map<Character, String> mapC2S = new HashMap<>();
	        for (int i = 0; i < pattern.length(); i++) {
	        	mapC2S.put(pattern.charAt(i), strs[i]);
	        }
	        StringBuilder sbC2S = new StringBuilder();
	        for (int i = 0; i < pattern.length(); i++) {
	        	sbC2S.append(mapC2S.get(pattern.charAt(i)) + " ");
	        }
	        String strC2S = sbC2S.subSequence(0, sbC2S.length() - 1).toString();
	        
	        Map<String, Character> mapS2C = new HashMap<>();
	        for (int i = 0; i < pattern.length(); i++) {
	        	mapS2C.put(strs[i], pattern.charAt(i));
	        }
	        StringBuilder sbS2C = new StringBuilder();
	        for (int i = 0; i < strs.length; i++) {
	        	sbS2C.append(mapS2C.get(strs[i]));
	        }
	        String strS2C = sbS2C.toString();
	        
	    	return strC2S.equals(str) && strS2C.equals(pattern);
	    }
	}
	
	public static void main(String[] args) {
		String pattern = "abb";
		String str = "dog cat dog";
		System.out.println(new Word_Pattern().new Solution().wordPattern(pattern, str));
				
	}
	
}
