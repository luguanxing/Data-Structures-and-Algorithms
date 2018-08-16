package medium;

public class Find_the_Duplicate_Number {

	class Solution {
		public int findDuplicate(int[] nums) {
			int[] flags = new int[nums.length + 1];
			for (int i = 0; i < nums.length; i++) {
				flags[nums[i]]++;
			}
			for (int i = 1; i <= nums.length; i++) {
				if (flags[i] > 1) {
					return i;
				}
			}
			return -1;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 3, 4, 2, 2 };
		System.out.println(new Find_the_Duplicate_Number().new Solution().findDuplicate(nums));
	}

}
