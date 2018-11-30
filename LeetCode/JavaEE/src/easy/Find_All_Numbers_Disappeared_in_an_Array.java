package easy;

import java.util.LinkedList;
import java.util.List;

public class Find_All_Numbers_Disappeared_in_an_Array {

	class Solution {
		public List<Integer> findDisappearedNumbers(int[] nums) {
			int len = nums.length;
			List<Integer> list = new LinkedList<>();
			// 标记数组范围[0, n]，用桶排序进行标记1-n中未出现的数字
			boolean[] flags = new boolean[len + 1];
			for (int num : nums) {
				flags[num] = true;
			}
			for (int i = 1; i <= len; i++) {
				if (!flags[i]) {
					list.add(i);
				}
			}
			return list;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
		System.out.println(new Find_All_Numbers_Disappeared_in_an_Array().new Solution().findDisappearedNumbers(nums));
	}

}
