package easy;

import java.util.HashMap;
import java.util.Map;

public class Jewels_and_Stones {

	class Solution {
	    public int numJewelsInStones(String J, String S) {
	    	// 也可以直接用一个int[128]
	        Map<Character, Integer> jewels = new HashMap<>();
	        for (int i = 0; i < J.length(); i++) {
	        	char Ji = J.charAt(i);
	        	if (jewels.get(Ji) == null) {
	        		jewels.put(Ji, 1);
	        	} else {
	        		jewels.put(Ji, jewels.get(Ji) + 1);
	        	}
	        }
	        int sum = 0;
	        // 检查是否添加过
	        for (int i = 0; i < S.length(); i++) {
	        	char Si = S.charAt(i);
	        	if (jewels.get(Si) != null) {
	        		sum++;
	        	}
	        }
	        return sum;
	    }
	}
	
	public static void main(String[] args) {
		String J = "aA";
		String S = "aAAbbbb";
		System.out.println(new Jewels_and_Stones().new Solution().numJewelsInStones(J, S));
	}
	
}
