package medium;

public class Rectangle_Area {

	class Solution {
		public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
			int sum = (C - A) * (D - B) + (G - E) * (H - F);
			int diff = 0;
			// 不重叠的只有四种情况，分别在上下左右(A的最下在B的最上，A的最上在B的最下，A的最左在B的最右，A的最右在B的最左)
			if (H < B || D < F || G < A || C < E) {
				diff = 0;
			} else {
				// 重叠需要分别投影到X轴和Y轴再计算重叠面积
				diff = (Math.min(G, C) - Math.max(A, E)) * (Math.min(D, H) - Math.max(B, F));
			}
			return sum - diff;
		}
	}

	public static void main(String[] args) {
		int A = -2, B = -2, C = 2, D = 2, E = -1, F = 4, G = 1, H = 6;
		System.out.println(new Rectangle_Area().new Solution().computeArea(A, B, C, D, E, F, G, H));
	}

}
