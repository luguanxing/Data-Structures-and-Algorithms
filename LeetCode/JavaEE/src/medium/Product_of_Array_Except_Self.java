package medium;

import java.util.Arrays;

public class Product_of_Array_Except_Self {

	class Solution {
		public int[] productExceptSelf(int[] nums) {
			int product = 1;
			for (int num : nums) {
				product *= num;
			}
			int[] result = new int[nums.length];
			for (int i = 0; i < nums.length; i++) {
				if (nums[i] != 0) {
					result[i] = product / nums[i];
				} else {
					// 遇到0重新计算
					result[i] = 1;
					for (int j = 0; j < nums.length; j++) {
						if (j != i) {
							result[i] *= nums[j];
						}
					}
				}
			}
			return result;
		}

		/*
		 * 更好的方式是建立一个左边累积ProductL[]和一个右边累积的数组ProductR[]，则result[i] =
		 * ProductL[i-1] * ProductR[i+1];
		 */
		public int[] productExceptSelf2(int[] nums) {
			int[] result = new int[nums.length];
			int[] productLeft = new int[nums.length];
			int[] productRight = new int[nums.length];
			int temp = 1;
			for (int i = 0; i < productLeft.length - 1; i++) {
				temp *= nums[i];
				productLeft[i + 1] = temp;
			}
			temp = 1;
			for (int i = productRight.length - 1; i > 0; i--) {
				temp *= nums[i];
				productRight[i - 1] = temp;
			}
			for (int i = 0; i < nums.length; i++) {
				if (i == 0) {
					result[i] = productRight[i];
				} else if (i == nums.length - 1) {
					result[i] = productLeft[i];
				} else {
					result[i] = productLeft[i] * productRight[i];
				}
			}
			return result;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 0 };
		System.out.println(Arrays.toString(new Product_of_Array_Except_Self().new Solution().productExceptSelf2(nums)));
	}

}
