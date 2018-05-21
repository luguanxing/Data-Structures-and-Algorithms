package easy;

public class Best_Time_to_Buy_and_Sell_Stock_II {

	class Solution {
		public int maxProfit(int[] prices) {
			if (prices == null || prices.length == 0) {
				return 0;
			}
			int maxProfit = 0;
			int curMaxProfit = 0;
			int lowestPrice = prices[0];
			for (int i = 1; i < prices.length; i++) {
				// 不亏就继续等，会亏马上卖
				if (prices[i] - lowestPrice >= curMaxProfit) {
					curMaxProfit = prices[i] - lowestPrice;
				} else {
					maxProfit += curMaxProfit;
					curMaxProfit = 0;
					lowestPrice = prices[i];
				}
				if (i == prices.length - 1) {
					maxProfit += curMaxProfit;
					curMaxProfit = 0;
					lowestPrice = prices[i];
				}
			}
			return maxProfit;
		}
	}

	class Solution_Better {
		public int maxProfit(int[] prices) {
			if (prices.length <= 1)
				return 0;
			int m = 0;
			// 计算比昨天赚多少
			for (int i = 1; i < prices.length; i++)
				prices[i - 1] = prices[i] - prices[i - 1];
			// 只在赚的那几天买卖
			for (int i = 0; i < prices.length - 1; i++)
				if (prices[i] > 0)
					m += prices[i];
			return m;
		}
	}

	public static void main(String[] args) {
		int[] prices = { 3, 3, 5, 0, 0, 3, 1, 4 };
		System.out.println(new Best_Time_to_Buy_and_Sell_Stock_II().new Solution().maxProfit(prices));
	}

}
