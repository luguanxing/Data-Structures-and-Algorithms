package hard;

public class Trapping_Rain_Water {

	class Solution {
		public int trap(int[] height) {
			// 空数组返回
			if (height == null || height.length == 0) {
				return 0;
			}
			// 计算从i点往左看到的最高点
			int[] leftMax = new int[height.length];
			leftMax[0] = height[0];
			for (int i = 1; i < height.length; i++) {
				if (leftMax[i - 1] < height[i]) {
					leftMax[i] = height[i];
				} else {
					leftMax[i] = leftMax[i - 1];
				}
			}
			// 计算从i点往右看到的最高点
			int[] rightMax = new int[height.length];
			rightMax[rightMax.length - 1] = height[height.length - 1];
			for (int i = rightMax.length - 2; i >= 0; i--) {
				if (rightMax[i + 1] < height[i]) {
					rightMax[i] = height[i];
				} else {
					rightMax[i] = rightMax[i + 1];
				}
			}
			// 计算在height[i]与左右最高点的较小值的差即为该店存水数目，否则本身为最高点存不了水
			int sum = 0;
			for (int i = 0; i < height.length; i++) {
				if (height[i] < leftMax[i] && height[i] < rightMax[i]) {
					sum += Math.min(leftMax[i], rightMax[i]) - height[i];
				}
			}
			return sum;
		}
	}

	public static void main(String[] args) {
		int[] height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
		System.out.println(new Trapping_Rain_Water().new Solution().trap(height));
	}

}
