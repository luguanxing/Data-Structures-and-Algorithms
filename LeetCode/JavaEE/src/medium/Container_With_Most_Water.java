package medium;

public class Container_With_Most_Water {

	class Solution {
		public int maxArea(int[] height) {
			// 使用滑动窗口计算
			int left = 0;
			int right = height.length - 1;
			int max = Integer.MIN_VALUE;
			while (left < right) {
				int curVal = Math.min(height[left], height[right]) * (right - left);
				if (curVal > max) {
					max = curVal;
				}
				// 再往里面如果左右边界更小没意义(更矮存水只会更少)，所以只让更短边找向后更大的
				if (height[left] < height[right]) {
					left++;
				} else {
					right--;
				}
			}
			return max;
		}
	}

	class Solution_Force {
		public int maxArea(int[] height) {
			int max = 0;
			for (int left = 0; left < height.length; left++) {
				for (int right = left + 1; right < height.length; right++) {
					int val = (right - left) * Math.min(height[left], height[right]);
					if (val > max) {
						max = val;
					}
				}
			}
			return max;
		}
	}

	public static void main(String[] args) {
		int[] height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
		System.out.println(new Container_With_Most_Water().new Solution().maxArea(height));
	}

}
