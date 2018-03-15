package medium;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Merge_Intervals {

	public class Interval {
		int start;
		int end;
		Interval() {
			start = 0;
			end = 0;
		}
		Interval(int s, int e) {
			start = s;
			end = e;
		}
		@Override
		public String toString() {
			return "[" + start + "," + end + "]";
		}
	}

	//这个合并区间不能用类似桶排序的方法，因为是实数集不是整数集
	class Solution {
		public List<Interval> merge(List<Interval> intervals) {
			//先按start排序所有interval
			Collections.sort(intervals, new Comparator<Interval>() {
				@Override
				public int compare(Interval o1, Interval o2) {
					return o1.start - o2.start;
				}
			});
			List<Interval> result = new ArrayList<>();
			//记录当前最右的值
			int maxRight = 0;
			for (Interval interval : intervals) {
				if (result.isEmpty()) {
					result.add(interval);
					maxRight = interval.end;
				} else {
					//如果当前最左比最右还大，直接添加该区间
					if (maxRight < interval.start) {
						result.add(interval);
						maxRight = interval.end;
					} else {
						//由于排序，当前左肯定比前一个左大，那判断当前右是不是也比最右(前一个右)大，是就合并，不是就忽略
						if (maxRight < interval.end) {
							maxRight = interval.end;
							result.get(result.size() - 1).end = maxRight;
						} else {
							
						}
					}
				}
			}
			return result;
		}
	}

	
	public static void main(String[] args) {
		Merge_Intervals main = new Merge_Intervals();
		List<Interval> intervals = new ArrayList<>();
		intervals.add(main.new Interval(2, 3));
		intervals.add(main.new Interval(2, 2));
		intervals.add(main.new Interval(3, 3));
		intervals.add(main.new Interval(1, 3));
		intervals.add(main.new Interval(5, 7));
		intervals.add(main.new Interval(2, 2));
		intervals.add(main.new Interval(4, 6));
		List<Interval> result = main.new Solution().merge(intervals);
		System.out.println(result);
	}
	
}
