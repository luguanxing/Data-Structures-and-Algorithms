package medium;

public class Integer_Break {

    public int integerBreak(int n) {
    	//动态规划计算最大积
    	int[] maxProduct = new int[n+1];
        maxProduct[1] = 1;
        for (int i = 2; i <= n; i++)
        	for (int j = 1; j <= i-1; j++)
        		maxProduct[i] = Math.max(maxProduct[i], Math.max(j*(i-j), j*maxProduct[i-j]));
    	return maxProduct[n];
    }
	
	public static void main(String[] args) {
		System.out.println(new Integer_Break().integerBreak(10));
	}

}
