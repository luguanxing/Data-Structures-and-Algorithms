
public class Solution {
	public static void main(String[] args) {
		int[] nums = {2, 7, 11, 15};
		Solution solution = new Solution();
		int ret[] = solution.twoSum(nums, 9);
		for (int i : ret) {
			System.out.print(i + " ");
		}
	}
	
	public int[] twoSum(int[] nums, int target) {
		int []arr = new int[2];
		for (int i = 0; i < nums.length; i++)
			for (int j = i+1; j < nums.length; j++)
				if (nums[i] + nums[j] == target) {
					arr[0] = i;
					arr[1] = j;
					break;
				}
		return arr;
	}
}
