package medium;

public class Maximum_Product_Subarray {

	class Solution {
		public int maxProduct(int[] nums) {
			if (nums.length == 0) {
				return 0;
			}
			// 需要维持正数和负数的极值
			int[] max = new int[nums.length];
			int[] min = new int[nums.length];
			max[0] = nums[0];
			min[0] = nums[0];
			// 极值只能是max[i-1]*nums[i]或min[i-1]*nums[i]或nums[i]中的一个
			for (int i = 1; i < nums.length; i++) {
				int result1 = max[i - 1] * nums[i];
				int result2 = min[i - 1] * nums[i];
				int result3 = nums[i];
				max[i] = Math.max(result1, Math.max(result2, result3));
				min[i] = Math.min(result1, Math.min(result2, result3));
			}
			// 从max中找出最大的
			int maxProduct = max[0];
			for (int i = 1; i < max.length; i++) {
				if (max[i] > maxProduct) {
					maxProduct = max[i];
				}
			}
			return maxProduct;
		}

		//先计算出任意product[left][right]，再取极值，但是耗时O(N^2)慢
		public int maxProduct_SLOW(int[] nums) {
			if (nums.length == 0) {
				return 0;
			}
			int[][] productsFromLeftToRight = new int[nums.length][nums.length];
			for (int left = 0; left < nums.length; left++) {
				for (int right = left; right < nums.length; right++) {
					int curProduct = nums[left];
					for (int k = left; k < right; k++) {
						curProduct *= nums[k + 1];
					}
					productsFromLeftToRight[left][right] = curProduct;
				}
			}
			int max = nums[0];
			for (int left = 0; left < nums.length; left++) {
				for (int right = left; right < nums.length; right++) {
					if (productsFromLeftToRight[left][right] > max) {
						max = productsFromLeftToRight[left][right];
					}
				}
			}
			return max;
		}
	}

	public static void main(String[] args) {
		Maximum_Product_Subarray main = new Maximum_Product_Subarray();
		Solution so = main.new Solution();
		int[] array = { -4, -3, -2 };
		System.out.println(so.maxProduct(array));
	}

}
