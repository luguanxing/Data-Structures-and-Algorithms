package medium;

import java.util.Arrays;

public class Search_for_a_Range {

	public static void main(String[] args) {
		int[] a = {1};
		int[] b = searchRange(a, 1);
		System.out.println(b[0] + " " + b[1]);
	}

	//先定位target，在向左右两侧扩展测距
    public static int[] searchRange(int[] nums, int target) {
        int[] ret = {-1, -1};
        int pos = Arrays.binarySearch(nums, target);
        if (pos < 0)
        	return ret;
        int left = pos;
        int right = pos;
        while (left > 0 && nums[left] == target) {
        	left--;
        }
        while (right < nums.length && nums[right] == target) {
        	right++;
        }
        if (nums[left] == target)
        	ret[0] = 0;
        else
        	ret[0] = left+1;
        ret[1] = right-1;
    	return ret;
    }
    
}
