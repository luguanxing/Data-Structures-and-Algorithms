package medium;

public class Partition_Equal_Subset_Sum {

	// 解决背包问题
	public static int packeting(int[] w, int[] v, int c) {
		int n = w.length;
		if (n == 0)
			return 0;
		// maxValue[n][c]表示在容量为c情况下只能拿前n件物品时最大值
		int[][] maxValue = new int[n][c + 1];
		for (int j = 0; j <= c; j++)
			maxValue[0][j] = (j >= w[0] ? v[0] : 0);
		for (int i = 1; i < n; i++)
			for (int j = 0; j <= c; j++) {
				// 不拿第i件物品时
				int noTakeItemI = maxValue[i - 1][j];
				maxValue[i][j] = noTakeItemI;
				if (j >= w[i]) {
					// 能拿且拿第i件物品时
					int takeItemI = maxValue[i - 1][j - w[i]] + v[i];
					maxValue[i][j] = Math.max(noTakeItemI, takeItemI);
				}
			}
		return maxValue[n - 1][c];
	}

	class Solution {
		public boolean canPartition(int[] nums) {
			int sum = 0;
			for (int num : nums) {
				sum += num;
			}
			if (sum % 2 == 1) {
				return false;
			}
			int half = sum / 2;
			int maxHalf = packeting(nums, nums, half);
			if (maxHalf == half) {
				return true;
			}
			return false;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2, 3, 5 };
		System.out.println(new Partition_Equal_Subset_Sum().new Solution().canPartition(nums));
	}

}
