package medium;

public class Minimum_Size_Subarray_Sum {

    class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            int len = nums.length;
            if (nums == null || len == 0) {
                return 0;
            }
            // 求和数组，计算序列和时能空间换时间，sums[i]=nums[0]+nums[1]+...nums[i]
            int[] sums = new int[len];
            sums[0] = nums[0];
            for (int i = 1; i < len; i++) {
                sums[i] = nums[i] + sums[i - 1];
            }
            // 滑动窗口，左闭右开
            int left = 0;
            int right = 1;
            int minLen = Integer.MAX_VALUE;
            while (right <= len) {
                // curSum = nums[left]+nums[left+1]+...nums[right-1]
                int curSum = 0;
                if (left == 0) {
                    curSum = sums[right - 1];
                } else {
                    curSum = sums[right - 1] - sums[left - 1];
                }
                // 少了，说明right要往右加数；多了，说明left要往右减数
                if (curSum < s) {
                    right++;
                } else {
                    minLen = Math.min(minLen, right - left);
                    left++;
                }
            }
            // minLen没变化说明没有找到
            if (minLen == Integer.MAX_VALUE) {
                return 0;
            }
            return minLen;
        }
    }

    public static void main(String[] args) {
        int s = 7;
        int[] nums = { 2, 3, 1, 2, 4, 3 };
        System.out.println(new Minimum_Size_Subarray_Sum().new Solution().minSubArrayLen(s, nums));
    }

}
