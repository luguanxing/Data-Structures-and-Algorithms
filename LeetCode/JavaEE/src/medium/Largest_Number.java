package medium;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;

public class Largest_Number {

	//比较两个数谁放前面：拼凑出来比一下不就知道了（注意可能数据大要用BigInteger）
	class Solution {
		public String largestNumber(int[] nums) {
			String[] nums_str = new String[nums.length];
			for (int i = 0; i < nums.length; i++) {
				nums_str[i] = "" + nums[i];
			}
			Arrays.sort(nums_str, new Comparator<String>() {
				@Override
				public int compare(String s1, String s2) {
					BigInteger big1 = new BigInteger(s1 + s2);
					BigInteger big2 = new BigInteger(s2 + s1);
					return big2.compareTo(big1);
				}
			});
			String result = "";
			for (String s : nums_str) {
				result += s;
			}
			while (result.charAt(0) == '0' && result.length() > 1) {
				result = result.substring(1);
			}
			return result;
		}
	}

	public static void main(String[] args) {
		Largest_Number main = new Largest_Number();
		int[] nums = { 0, 0 };
		System.out.println(main.new Solution().largestNumber(nums));
	}

}
