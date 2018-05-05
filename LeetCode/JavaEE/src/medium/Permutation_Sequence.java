package medium;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Permutation_Sequence {

	class Solution {
		List<List<Integer>> allResult = new LinkedList<>();

		public void permutation(List<Integer> nums, List<Integer> curResult) {
			if (nums.isEmpty()) {
				// 保存新值不能保存引用
				allResult.add(new ArrayList(curResult));
				return;
			}
			for (int i = 0; i < nums.size(); i++) {
				List<Integer> noTakeI = new LinkedList<>(nums);
				noTakeI.remove(i);
				curResult.add(nums.get(i));
				permutation(noTakeI, curResult);
				curResult.remove(curResult.size() - 1);
			}
		}

		public String getPermutation(int n, int k) {
			List<Integer> nums = new LinkedList<>();
			List<Integer> curResult = new LinkedList<>();
			for (int i = 1; i <= n; i++) {
				nums.add(i);
			}
			permutation(nums, curResult);
			List<Integer> result = allResult.get(k - 1);
			StringBuilder sb = new StringBuilder();
			for (Integer num : result) {
				sb.append(num);
			}
			return sb.toString();
		}
	}

	public static void main(String[] args) {
		int n = 3;
		int k = 3;
		System.out.println(new Permutation_Sequence().new Solution().getPermutation(n, k));
	}

}
