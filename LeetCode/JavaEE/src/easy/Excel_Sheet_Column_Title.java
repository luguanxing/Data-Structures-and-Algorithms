package easy;

public class Excel_Sheet_Column_Title {

	class Solution {
		public String convertToTitle(int n) {
			StringBuilder sb = new StringBuilder();
			while (n > 26) {
				int index = n % 26;
				n = n / 26;
				if (index == 0) {
					sb.insert(0, (char) ('Z'));
					n--;
				} else {
					sb.insert(0, (char) ('A' + index - 1));
				}
			}
			sb.insert(0, (char) ('A' + n - 1));
			return sb.toString();
		}
	}

	public static void main(String[] args) {
		int n = 52;
		System.out.println(new Excel_Sheet_Column_Title().new Solution().convertToTitle(n));
	}

}
