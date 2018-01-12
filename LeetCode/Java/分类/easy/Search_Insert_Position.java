package easy;

import java.util.Arrays;

public class Search_Insert_Position {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] a = {1, 3};
		System.out.println("ret="+searchInsert(a, 2));
	}

    public static int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
        	int mid = (low + high) >>> 1;
            int midVal = nums[mid];
            if (midVal < target)
                low = mid + 1;
            else if (midVal > target)
                high = mid - 1;
            else
                return mid;
        }
        if (low > high)
        	return low;
        else
        	return high;
    }
	
//    public static int searchInsert(int[] nums, int target) {
//    	for (int i = 0; i < nums.length; i++) {
//			if (target == nums[i] || target < nums[i])
//				return i;
//		}
//    	return nums.length;
//    }
	
}
