package easy;

public class Factorial_Trailing_Zeroes {

	class Solution {
		// 末尾0个数只需2和5较小值，由于2很多，只需计算5个数
		// 由于n!=1*2*3...*n，计算n!中的5只需不断除以5即可(如20!含1*5,2*5,3*5,4*5,5*5)
		public int trailingZeroes(int n) {
			int sum = 0;
			while (n > 0) {
				sum += n / 5;
				n /= 5;
			}
			return sum;
		}
	}

	class Solution_TLE {
		public int trailingZeroes(int n) {
			int sumOf2 = 0;
			int sumOf5 = 0;
			for (int i = 1; i <= n; i++) {
				int num = i;
				while (num % 2 == 0) {
					num /= 2;
					sumOf2++;
				}
				while (num % 5 == 0) {
					num /= 5;
					sumOf5++;
				}
			}
			return Math.min(sumOf2, sumOf5);
		}
	}

	public static void main(String[] args) {
		int n = 10;
		System.out.println(new Factorial_Trailing_Zeroes().new Solution().trailingZeroes(n));
	}

}
