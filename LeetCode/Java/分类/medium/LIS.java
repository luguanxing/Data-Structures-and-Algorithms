package medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LIS {

	private int[][] lcs_length = null;
	private int[][] lcs_direction = null;
	private List<Integer> lcs_result = new ArrayList<Integer>();
	
	public void print(int[][] A) {
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[i].length; j++) {
				System.out.print(A[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public void LCS(int[] X, int[] Y) {
		int m = X.length;
		int n = Y.length;
		lcs_length = new int[m+1][n+1];
		lcs_direction = new int[m+1][n+1];
		for (int i = 0; i <= m; i++)
			lcs_length[i][0] = 0;
		for (int i = 0; i <= n; i++)
			lcs_length[0][i] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (X[i-1] == Y[j-1]) {
					lcs_length[i][j] = lcs_length[i-1][j-1] + 1;
					lcs_direction[i][j] = 1;
				} else if (lcs_length[i-1][j] >= lcs_length[i][j-1]) {
					lcs_length[i][j] = lcs_length[i-1][j];
					lcs_direction[i][j] = 2;
				} else {
					lcs_length[i][j] = lcs_length[i][j-1];
					lcs_direction[i][j] = 3;
				}
			}
		}
		print(lcs_length);
		System.out.println();
		print(lcs_direction);
		System.out.println();
		followResultOfLCS(X, m, n);
		System.out.println();
		System.out.println(getReusltOfLCS());
		System.out.println();
		System.out.println(lengthOfLCS());
	}
	
	public void followResultOfLCS(int[] X, int m, int n) {
		if (m == 0 || n == 0)
			return;
		if (lcs_direction[m][n] == 1) {
			followResultOfLCS(X, m-1, n-1);
			lcs_result.add(X[m-1]);
		} else if (lcs_direction[m][n] == 2) {
			followResultOfLCS(X, m-1, n);
		} else if (lcs_direction[m][n] == 3) {
			followResultOfLCS(X, m, n-1);
		}
	}
	
	public List<Integer> getReusltOfLCS() {
		return lcs_result;
	}
	
	public int lengthOfLCS() {
		int max = 0;
		for (int i = 0; i < lcs_length.length; i++) {
			for (int j = 0; j < lcs_length[i].length; j++) {
				if (lcs_length[i][j] > max) {
					max = lcs_length[i][j];
				}
			}
		}
		return max;
	}
	
	public static void main(String[] args) {
		LIS so = new LIS();
		int[] X = {1, 2, 3, 2, 4, 1, 2};
		int[] Y = {2, 4, 3, 1, 2, 1};
		so.LCS(X, Y);
	}
	
}
