package easy;

public class Range_Sum_Query {

	class NumArray {
		private int[] array = null;

		private int[] sum = null;

		public NumArray(int[] nums) {
			if (nums == null)
				return;
			array = nums;
			sum = new int[nums.length + 1];
			// 求和区间左闭右开
			for (int i = 1; i <= nums.length; i++) {
				sum[i] += sum[i - 1] + nums[i - 1];
			}
		}

		public int sumRange(int i, int j) {
			if (sum == null)
				return 0;
			return sum[j + 1] - sum[i];
		}
	}

}
