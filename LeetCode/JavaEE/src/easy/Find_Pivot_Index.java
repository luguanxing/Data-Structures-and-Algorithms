package easy;

public class Find_Pivot_Index {

	class Solution {
		public int pivotIndex(int[] nums) {
			if (nums == null || nums.length == 0) {
				return -1;
			}
			// 求和区间：左闭右开
			long sum0ToI[] = new long[nums.length];
			sum0ToI[0] = nums[0];
			for (int i = 1; i < nums.length; i++) {
				sum0ToI[i] = sum0ToI[i - 1] + nums[i];
			}
			// 滑动窗口
			long leftSum = 0;
			long rightSum = sum0ToI[sum0ToI.length - 1] - sum0ToI[0];
			int pivot = 0;
			do {
				if (leftSum == rightSum) {
					return pivot;
				}
				leftSum = sum0ToI[pivot];
				if (pivot < nums.length - 1) {
					rightSum = sum0ToI[sum0ToI.length - 1] - sum0ToI[++pivot];
				} else {
					rightSum = 0;
					++pivot;
				}
			} while (pivot < nums.length);
			return -1;
		}
	}

	class Solution_Better {
		public int pivotIndex(int[] nums) {
			int sum = 0;
			for (int num : nums)
				sum += num;
			int tmp = 0;
			// 左边*2+当前==总和 即可，即由等式((总和-当前)/2==左==右，2x+nums[i]==sum)
			for (int i = 0; i < nums.length; i++) {
				if (tmp * 2 + nums[i] == sum)
					return i;
				tmp += nums[i];
			}
			return -1;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, -1, 0 };
		System.out.println(new Find_Pivot_Index().new Solution().pivotIndex(nums));
	}

}
