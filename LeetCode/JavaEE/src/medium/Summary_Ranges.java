package medium;

import java.util.ArrayList;
import java.util.List;

public class Summary_Ranges {

	class Solution {
		public List<String> summaryRanges(int[] nums) {
			if (nums == null) {
				return null;
			}
			if (nums.length == 0) {
				return new ArrayList<>();
			}
			int last = nums[0];
			int cur = nums[0];
			List<String> list = new ArrayList<>();
			for (int i = 1; i < nums.length; i++) {
				// 出现不连续的断层时保存下来并继续向后
				if (nums[i] - cur != 1) {
					if (last != cur) {
						list.add(last + "->" + cur);
					} else {
						list.add(cur + "");
					}
					last = nums[i];
				}
				cur = nums[i];
			}
			// 处理末尾情况即当前最后一个范围
			if (last != cur) {
				list.add(last + "->" + cur);
			} else {
				list.add(cur + "");
			}
			return list;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 2, 4, 5, 7 };
		System.out.println(new Summary_Ranges().new Solution().summaryRanges(nums));
	}

}
