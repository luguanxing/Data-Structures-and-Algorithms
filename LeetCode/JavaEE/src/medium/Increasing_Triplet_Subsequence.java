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
            // ��¼�����Сֵ
            minLeftNum[0] = nums[0];
            for (int i = 1; i < len; i++) {
                minLeftNum[i] = Math.min(nums[i], minLeftNum[i - 1]);
            }
            // ��¼�ұ����ֵ
            maxRightNum[len - 1] = nums[len - 1];
            for (int i = len - 2; i >= 0; i--) {
                maxRightNum[i] = Math.max(nums[i], maxRightNum[i + 1]);
            }
            // ���������ߴ��ֱ��ұ�С�ģ��ҵ�����
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
