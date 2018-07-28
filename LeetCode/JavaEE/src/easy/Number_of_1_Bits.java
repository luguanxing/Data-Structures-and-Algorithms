package easy;

public class Number_of_1_Bits {

	public class Solution {
		public int hammingWeight(int n) {
			String binaryString = Integer.toBinaryString(n);
			int result = 0;
			for (int i = 0; i < binaryString.length(); i++) {
				if (binaryString.charAt(i) == '1') {
					result++;
				}
			}
			return result;
		}
	}
	
	public static void main(String[] args) {
		System.out.println(new Number_of_1_Bits().new Solution().hammingWeight(11));
	}

}
