package hard;

public class Interleaving_String {

	class Solution {
		public boolean isInterleave(String s1, String s2, String s3) {
			if (s1.length() + s2.length() != s3.length()) {
				return false;
			}
			// 动态规划:s1, s2只有两个字符串，因此可以展平为一个二维地图，判断是否能从左上角走到右下角
			boolean[][] dp = new boolean[s1.length() + 1][s2.length() + 1];
			// 初始化s1和s2行，要求连续相同的才能匹配
			dp[0][0] = true;
			for (int i = 1; i <= s2.length(); i++) {
				if (dp[0][i - 1] && (s2.charAt(i - 1) == s3.charAt(i - 1))) {
					dp[0][i] = true;
				}
			}
			for (int i = 1; i <= s1.length(); i++) {
				if (dp[i - 1][0] && s1.charAt(i - 1) == s3.charAt(i - 1)) {
					dp[i][0] = true;
				}
			}
			// 判断是从是从左来的即s2[j-1]匹配s3[i+j-1]还是从上来的即s1[i-1]匹配s3[i+j-1]
			for (int y = 1; y <= s1.length(); y++) {
				for (int x = 1; x <= s2.length(); x++) {
					if ((dp[y][x - 1] && s2.charAt(x - 1) == s3.charAt(x + y - 1))
							|| (dp[y - 1][x] && s1.charAt(y - 1) == s3.charAt(x + y - 1))) {
						dp[y][x] = true;
					}
				}
			}
			return dp[s1.length()][s2.length()];
		}
	}

	public static void main(String[] args) {
		String s1 = "x";
		String s2 = "s";
		String s3 = "sx";
		System.out.println(new Interleaving_String().new Solution().isInterleave(s1, s2, s3));
	}

}
