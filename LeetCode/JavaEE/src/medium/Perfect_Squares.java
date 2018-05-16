package medium;

public class Perfect_Squares {

	class Solution {
		public int numSquares(int n) {
			if (n == 0) {
				return 0;
			}
			// dp[i]表示用平方数凑成i的最少个数
			int dp[] = new int[n + 1];
			dp[0] = 0;
			dp[1] = 1;
			for (int i = 2; i <= n; i++) {
				// 是平方数则只需一个数凑，否则动态规划求拼凑的最少个数，注意由于对称只需循环到n/2
				if ((int) Math.sqrt(i) * (int) Math.sqrt(i) == i) {
					dp[i] = 1;
				} else {
					int min = i;
					for (int j = 1; j * j <= i; j++) {
						min = Math.min(min, dp[j * j] + dp[i - j * j]);
					}
					dp[i] = min;
				}
			}
			return dp[n];
		}
	}

	public static void main(String[] args) {
		int n = 12;
		System.out.println(new Perfect_Squares().new Solution().numSquares(n));
	}

}
