package easy;

public class Reverse_Bits {

	public class Solution {
		public int reverseBits(int n) {
			// java本身不支持解析unsigned，所以不能用一般的方式解析n，只能用位运算移动达到翻转效果
			int result = 0;
			for (int i = 0; i < 31; i++) {
				result |= n & 1;
				result <<= 1;
				n >>= 1;
			}
			result |= n & 1;
			return result;
		}
	}

	public static void main(String[] args) {
		int n = 43261596;
		System.out.println(new Reverse_Bits().new Solution().reverseBits(n));
	}

}
