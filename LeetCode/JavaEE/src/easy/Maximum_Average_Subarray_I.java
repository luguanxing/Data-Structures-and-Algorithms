package easy;

public class Maximum_Average_Subarray_I {

	class Solution {
		public double findMaxAverage(int[] nums, int k) {
			double maxSum = 0;
			double curSum = 0;
			for (int i = 0; i < k; i++) {
				curSum += nums[i];
			}
			maxSum = curSum;
			// 这里应该只计算两个数而不是把a[i-k+1]-a[i]都计算一遍
			for (int i = k; i < nums.length; i++) {
				curSum -= nums[i - k];
				curSum += nums[i];
				maxSum = Math.max(maxSum, curSum);
			}
			return maxSum / k;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 12, -5, -6, 50, 3 };
		int k = 4;
		System.out.println(new Maximum_Average_Subarray_I().new Solution().findMaxAverage(nums, k));
	}

}
