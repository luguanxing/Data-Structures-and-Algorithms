package medium;

public class Coin_Change_2 {

	class Solution {
		public int change(int amount, int[] coins) {
			// ways[i][j]表示用前i枚硬币拼凑j元的方法
			int[][] ways = new int[coins.length + 1][amount + 1];
			// 初始化
			ways[0][0] = 1;
			// 逐枚硬币的计算出ways[i][j]
			for (int i = 1; i <= coins.length; i++) {
				ways[i][0] = 1;
				for (int j = 1; j <= amount; j++) {
					// {前i枚硬币拼凑j元的方法}即{前i-1枚硬币拼凑j-k*coins[i]元加上这k*coins[i]}的方法数
					for (int k = 0; k <= j / coins[i - 1]; k++) {
						ways[i][j] += ways[i - 1][j - k * coins[i - 1]];
					}
				}
			}
			return ways[coins.length][amount];
		}

		// 优化版，不需要二维数组
		public int change_opt(int amount, int[] coins) {
			int[] dp = new int[amount + 1];
			dp[0] = 1;
			// 逐枚硬币更新
			for (int coin : coins) {
				for (int i = coin; i <= amount; i++) {
					dp[i] += dp[i - coin];
				}
			}
			return dp[amount];
		}
	}

	public static void main(String[] args) {
		int[] coins = { 1, 2, 5 };
		System.out.println(new Coin_Change_2().new Solution().change(5, coins));
	}

}
