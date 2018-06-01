package easy;

import java.util.Arrays;

public class Contains_Duplicate {

	class Solution {
		public boolean containsDuplicate(int[] nums) {
			if (nums == null) {
				return false;
			}
			Arrays.sort(nums);
			for (int i = 1; i < nums.length; i++) {
				if (nums[i] == nums[i - 1]) {
					return true;
				}
			}
			return false;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2, 3, 1 };
		System.out.println(new Contains_Duplicate().new Solution().containsDuplicate(nums));
	}

}
