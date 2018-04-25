package easy;

public class Majority_Element {

	class Solution {
		public int majorityElement(int[] nums) {
			if (nums == null) {
				return 0;
			}
			int target = nums[0];
			int times = 1;
			for (int i = 1; i < nums.length; i++) {
				if (nums[i] == target) {
					times++;
				} else {
					times--;
					if (times == 0) {
						target = nums[i];
						times = 1;
					}
				}
			}
			return target;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 3, 3, 4 };
		System.out.println(new Majority_Element().new Solution().majorityElement(nums));
	}

}
