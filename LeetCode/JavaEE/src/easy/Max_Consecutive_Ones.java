package easy;

public class Max_Consecutive_Ones {

    class Solution {
        public int findMaxConsecutiveOnes(int[] nums) {
            int max = 0;
            int cur = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == 1) {
                    cur++;
                    max = Math.max(cur, max);
                } else {
                    cur = 0;
                }
            }
            return max;
        }
    }

    public static void main(String[] args) {
        int[] nums = { 1, 1, 0, 1, 1, 1 };
        System.out.println(new Max_Consecutive_Ones().new Solution().findMaxConsecutiveOnes(nums));
    }

}
