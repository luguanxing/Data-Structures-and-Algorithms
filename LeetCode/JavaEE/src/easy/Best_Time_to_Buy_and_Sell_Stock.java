package easy;

public class Best_Time_to_Buy_and_Sell_Stock {

	class Solution {
		public int maxProfit(int[] prices) {
			if (prices == null || prices.length == 0) {
				return 0;
			}
			int maxProfit = 0;
			int lowestPrice = prices[0];
			for (int i = 1; i < prices.length; i++) {
				int curPrice = prices[i];
				if (curPrice < lowestPrice) {
					lowestPrice = curPrice;
				}
				if (curPrice - lowestPrice > maxProfit) {
					maxProfit = curPrice - lowestPrice;
				}
			}
			return maxProfit;
		}
	}

	public static void main(String[] args) {
		int[] prices = { 7, 1, 5, 3, 6, 4 };
		System.out.println(new Best_Time_to_Buy_and_Sell_Stock().new Solution().maxProfit(prices));
	}

}
