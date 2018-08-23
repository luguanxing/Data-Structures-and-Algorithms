package easy;

public class Add_Digits {

	class Solution {
		// 更快的方法是找规律：9个数一次循环直接return (num-1)%9+1;
		public int addDigits(int num) {
			while (num >= 10) {
				int sum = 0;
				while (num >= 10) {
					sum += num % 10;
					num /= 10;
				}
				sum += num;
				num = sum;
			}
			return num;
		}
	}

	public static void main(String[] args) {
		int num = 38;
		System.out.println(new Add_Digits().new Solution().addDigits(num));
	}

}
