import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		int len = s.length();
		int[][] dp = new int[len][len];
		// 初始化dp[i][i]=1
		for (int i = 0; i < len; i++) {
			dp[i][i] = 1;
		}
		// 计算dp[left][right]
		// 若s[left]!=s[right]则s[left-right]不能构成回文要去重
		// 若s[left]==s[right]则s[left-right]可以构成回文要去重
		for (int left = len - 1; left >= 0; left--) {
			for (int right = left + 1; right < len; right++) {
				dp[left][right] += dp[left][right - 1] + dp[left + 1][right];
				if (s.charAt(left) == s.charAt(right)) {
					dp[left][right] += 1;
				} else {
					dp[left][right] -= dp[left + 1][right - 1];
				}
			}
		}
		System.out.println(dp[0][len - 1]);
	}

}
