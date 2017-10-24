package medium;

import java.util.Arrays;

public class Add_Binary {

	public class Solution {
	    public String addBinary(String a, String b) {
	    	int alen = a.length();
	    	int blen = b.length();
	    	int[] x = new int[alen+1];
	    	int[] y = new int[blen+1];
	    	for (int i = 1; i <= alen; i++)
	    		if (a.charAt(i-1) == '1')
	    			x[i] = 1;
	    		else
	    			x[i] = 0;
	    	for (int i = 1; i <= blen; i++)
	    		if (b.charAt(i-1) == '1')
	    			y[i] = 1;
	    		else
	    			y[i] = 0;	
	    	if (alen < blen) {
	    		for (int i = 0; i < alen; i++)
	    			y[blen-i] += x[alen-i];
	    		for (int i = blen; i >=1; i--)
	    			if (y[i] >= 2) {
	    				y[i] -= 2;
	    				y[i-1] += 1;
	    			}
	    		StringBuffer sb = new StringBuffer();
	    		for (int i : y)
					sb.append(i);
	    		if (sb.charAt(0) =='0')
	    			sb.deleteCharAt(0);
	    		return sb.toString();
	    	} else {
	    		for (int i = 0; i < blen; i++)
	    			x[alen-i] += y[blen-i];
	    		for (int i = alen; i >=1; i--)
	    			if (x[i] >= 2) {
	    				x[i] -= 2;
	    				x[i-1] += 1;
	    			}
	    		StringBuffer sb = new StringBuffer();
	    		for (int i : x)
					sb.append(i);
	    		if (sb.charAt(0) =='0')
	    			sb.deleteCharAt(0);
	    		return sb.toString();
	    	}
	    }
	}
	
	public static void main(String[] args) {
		Add_Binary main = new Add_Binary();
		System.out.println(main.new Solution().addBinary("111", "1"));
	}

}
