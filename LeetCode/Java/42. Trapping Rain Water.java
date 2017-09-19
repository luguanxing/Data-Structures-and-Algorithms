package hard;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Trapping_Rain_Water {

    public int trap(int[] heights) {
    	if (heights.length == 0)
    		return 0;
    	int waterSum = 0;
    	
    	//先找最高点
    	int maxHeight = heights[0];
    	int maxIndex = 0;
        for (int x = 0; x < heights.length; x++) {
        	int height = heights[x];
			if (height > maxHeight) {
				maxHeight = height;
				maxIndex = x;
			}
		}
        
        //从左往最高点找水坑
        int leftMax = 0;
        for (int left = 0; left < maxIndex; left++) {
        	if (heights[left] > leftMax) {
        		leftMax = heights[left];
        	} else {
        		waterSum += leftMax - heights[left];
        	}
        }
        
        //从右往最高点找水坑
        int rightMax = 0;
        for (int right = heights.length - 1; right > maxIndex; right--) {
        	if (heights[right] > rightMax) {
        		rightMax = heights[right];
        	} else {
        		waterSum += rightMax - heights[right];
        	}
        }
        
    	return waterSum;
    }
	
	public static void main(String[] args) {
		Trapping_Rain_Water main = new Trapping_Rain_Water();
		System.out.println(main.trap(new int[] {1,0,1}));
	}

}
