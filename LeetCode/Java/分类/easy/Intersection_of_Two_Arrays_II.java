package easy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Intersection_of_Two_Arrays_II {

    public int[] intersect(int[] nums1, int[] nums2) {
        Map map = new HashMap();
        for (int i : nums1)
        	map.put(i, 0);
        for (int i : nums2)
        	map.put(i, 0);
        for (int i : nums1)
        	map.put(i, Integer.parseInt(map.get(i).toString())+1);
        List<Integer> list = new ArrayList();
        for (int i : nums2) {
        	int checkNum = Integer.parseInt(map.get(i).toString());
        	if (checkNum > 0) {
        		list.add(i);
        		map.put(i, checkNum-1);
        	}
        }
        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++)
        	res[i] = list.get(i);
        return res;
    }
	
	public static void main(String[] args) {
		int[] nums1 = {};
		int[] nums2 = {1};
		System.out.println(Arrays.toString(new Intersection_of_Two_Arrays_II().intersect(nums1, nums2)));
	}

}
