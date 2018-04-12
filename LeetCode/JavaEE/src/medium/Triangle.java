package medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Triangle {

	class Solution {
		public int minimumTotal(List<List<Integer>> triangle) {
			if (triangle.isEmpty()) {
				return 0;
			}
			int[] dp = new int[triangle.size()];
			dp[0] = triangle.get(0).get(0);
			for (int i = 1; i < triangle.size(); i++) {
				int[] temp = Arrays.copyOf(dp, i);
				if (i >= 2) {
					for (int j = 1; j < i; j++) {
						dp[j] = Math.min(temp[j - 1], temp[j]) + triangle.get(i).get(j);
					}
				}
				dp[0] = temp[0] + triangle.get(i).get(0);
				dp[i] = temp[i - 1] + triangle.get(i).get(i);
			}
			int min = dp[0];
			for (int i = 1; i < triangle.size(); i++) {
				if (dp[i] < min) {
					min = dp[i];
				}
			}
			return min;
		}
	}

	public static void main(String[] args) {
		List<List<Integer>> triangle = new ArrayList<>();
		List<Integer> l1 = new ArrayList<>();
		List<Integer> l2 = new ArrayList<>();
		List<Integer> l3 = new ArrayList<>();
		List<Integer> l4 = new ArrayList<>();
		l1.add(2);
		l2.add(3);
		l2.add(4);
		l3.add(6);
		l3.add(5);
		l3.add(7);
		l4.add(4);
		l4.add(1);
		l4.add(8);
		l4.add(3);
		triangle.add(l1);
		triangle.add(l2);
		triangle.add(l3);
		triangle.add(l4);
		System.out.println(new Triangle().new Solution().minimumTotal(triangle));
	}

}
