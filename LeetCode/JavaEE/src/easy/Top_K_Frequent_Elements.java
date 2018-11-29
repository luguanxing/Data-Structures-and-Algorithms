package easy;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Top_K_Frequent_Elements {

	class Solution {
		class KV implements Comparable<KV> {
			int key;
			int value;
			public KV(int key, int value) {
				this.key = key;
				this.value = value;
			}
			@Override
			public int compareTo(KV that) {
				return that.value - this.value;
			}
			@Override
			public String toString() {
				return this.key + "->" + this.value;
			}
		}

		public List<Integer> topKFrequent(int[] nums, int k) {
			// map存储各个数字出现的频率
			Map<Integer, Integer> map = new HashMap<>();
			for (int num : nums) {
				if (!map.containsKey(num)) {
					map.put(num, 1);
				} else {
					map.put(num, map.get(num) + 1);
				}
			}
			// 保存结果到KV结构并按照频率value排序
			List<KV> list = new ArrayList<>();
			for (Integer key : map.keySet()) {
				Integer value = map.get(key);
				list.add(new KV(key, value));
			}
			Collections.sort(list);
			// 返回排序结果前k个
			List<Integer> result = new ArrayList<>();
			for (int i = 0; i < k; i++) {
				result.add(list.get(i).key);
			}
			return result;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 1, 1, 1, 2, 2, 3 };
		int k = 2;
		System.out.println(new Top_K_Frequent_Elements().new Solution().topKFrequent(nums, k));
	}

}
