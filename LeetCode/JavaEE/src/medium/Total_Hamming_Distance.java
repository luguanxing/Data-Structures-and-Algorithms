package medium;

public class Total_Hamming_Distance {

    class Solution {
        public int totalHammingDistance(int[] nums) {
            int sum = 0;
            // 对32位的每一位计数nums有多少个0和多少个1，每一位能产生1个数*0个数个距离(相对其它数在该位的异或)
            for (int index = 0; index < 32; index++) {
                int oneNums = 0;
                int zeroNums = 0;
                for (int num : nums) {
                    oneNums += ((num & (1 << index)) != 0) ? 1 : 0;
                    zeroNums += ((num & (1 << index)) == 0) ? 1 : 0;
                }
                sum += oneNums * zeroNums;
            }
            return sum;
        }
    }

    class Solution_TLE {
        public int totalHammingDistance(int[] nums) {
            int sum = 0;
            for (int i = 0; i < nums.length; i++) {
                for (int j = i + 1; j < nums.length; j++) {
                    sum += getHammingDistance(nums[i], nums[j]);
                }
            }
            return sum;
        }

        public int getHammingDistance(int num1, int num2) {
            int xor = num1 ^ num2;
            String xorNum = Integer.toBinaryString(xor);
            char[] xorNums = xorNum.toCharArray();
            int sum = 0;
            for (char c : xorNums) {
                if (c == '1') {
                    sum++;
                }
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        int[] nums = { 4, 14, 2 };
        System.out.println(new Total_Hamming_Distance().new Solution().totalHammingDistance(nums));
    }

}
