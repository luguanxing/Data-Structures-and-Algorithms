package medium;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Minimum_Time_Difference {

	class Solution {
		public int findMinDifference(List<String> timePoints) {
			List<Integer> times = new ArrayList<>();
			for (String timeStr : timePoints) {
				int hour = (timeStr.charAt(0) - '0') * 10 + (timeStr.charAt(1) - '0');
				int minute = (timeStr.charAt(3) - '0') * 10 + (timeStr.charAt(4) - '0');
				int time = hour * 60 + minute;
				times.add(time);
				times.add(time + 24 * 60); // 对于跨天的情况也算入
			}
			Collections.sort(times);
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < times.size() - 1; i++) {
				if (times.get(i + 1) - times.get(i) < min) {
					min = times.get(i + 1) - times.get(i);
				}
			}
			return min;
		}
	}

	public static void main(String[] args) {
		List<String> timeStrs = new ArrayList<>();
		timeStrs.add("05:31");
		timeStrs.add("22:08");
		timeStrs.add("00:35");
		System.out.println(new Minimum_Time_Difference().new Solution().findMinDifference(timeStrs));
	}

}
