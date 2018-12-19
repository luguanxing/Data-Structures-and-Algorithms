package medium;

public class Increasing_Triplet_Subsequence {

    class Solution {
        public boolean increasingTriplet(int[] nums) {
            if (nums == null || nums.length < 3) {
                return false;
            }
            int len = nums.length;
            int[] minLeftNum = new int[len];
            int[] maxRightNum = new int[len];
            // 记录左边最小值
            minLeftNum[0] = nums[0];
            for (int i = 1; i < len; i++) {
                minLeftNum[i] = Math.min(nums[i], minLeftNum[i - 1]);
            }
            // 记录右边最大值
            maxRightNum[len - 1] = nums[len - 1];
            for (int i = len - 2; i >= 0; i--) {
                maxRightNum[i] = Math.max(nums[i], maxRightNum[i + 1]);
            }
            // 找数组比左边大又比右边小的，找到即可
            for (int i = 1; i < len - 1; i++) {
                if (minLeftNum[i - 1] < nums[i] && nums[i] < maxRightNum[i + 1]) {
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        int[] nums = { 3, 2, 4, 1, 5 };
        System.out.println(new Increasing_Triplet_Subsequence().new Solution().increasingTriplet(nums));
    }

}
