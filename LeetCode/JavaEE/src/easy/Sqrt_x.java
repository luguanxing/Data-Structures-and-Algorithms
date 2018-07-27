package easy;

public class Sqrt_x {

	class Solution {
	    public int mySqrt(long x) {
	    	// 使用long防止太大或res * res越界，另外可直接诶返回(int)Math.sqrt(x)
	    	long res = 0;
	        while (res * res <= x) {
	        	res++;
	        }
	        return (int) (res - 1);
	    }
	}
	
	public static void main(String[] args) {
		System.out.println(new Sqrt_x().new Solution().mySqrt(2147395600));
	}
	
}
