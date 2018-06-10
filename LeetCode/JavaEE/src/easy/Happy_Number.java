package easy;

import java.util.HashSet;
import java.util.Set;

public class Happy_Number {

	class Solution {
		public boolean isHappy(int n) {
			int sum = n;
			Set<Integer> set = new HashSet<>();
			while (sum != 1) {
				n = sum;
				sum = 0;
				while (n > 0) {
					sum += (n % 10) * (n % 10);
					n /= 10;
				}
				if (set.contains(sum)) {
					return false;
				} else {
					set.add(sum);
				}
			}
			return true;
		}
	}

	public static void main(String[] args) {
		int n = 19;
		System.out.println(new Happy_Number().new Solution().isHappy(n));
	}

}
