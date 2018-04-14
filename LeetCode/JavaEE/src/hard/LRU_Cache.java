package hard;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class LRU_Cache {

	class LRUCache {

		int capacity = 0;

		// 使用队列维持LRU，最新的放在堆首
		List<Map<Integer, Integer>> list = new ArrayList<>();

		// 初始化容量
		public LRUCache(int capacity) {
			this.capacity = capacity;
		}

		// 获取并更新
		public int get(int key) {
			for (int i = 0; i < list.size(); i++) {
				Map<Integer, Integer> map = list.get(i);
				if (map.containsKey(key)) {
					list.remove(i);
					list.add(0, map);
					return map.get(key);
				}
			}
			return -1;
		}

		// 添加，如果已含则更新，不含则添加
		public void put(int key, int value) {
			for (int i = 0; i < list.size(); i++) {
				Map<Integer, Integer> map = list.get(i);
				if (map.containsKey(key)) {
					list.remove(i);
					map.put(key, value);
					list.add(0, map);
					return;
				}
			}
			if (list.size() == capacity) {
				list.remove(list.size() - 1);
			}
			Map<Integer, Integer> map = new HashMap<>();
			map.put(key, value);
			list.add(0, map);
		}

		// 检查输出
		@Override
		public String toString() {
			return list.toString();
		}
	}

	public static void main(String[] args) {
		LRUCache cache = new LRU_Cache().new LRUCache(2);
		cache.put(1, 1);
		System.out.println(cache);
		cache.put(2, 2);
		System.out.println(cache);
		cache.get(1); // returns 1
		System.out.println(cache);
		cache.put(3, 3); // evicts key 2
		System.out.println(cache);
		cache.get(2); // returns -1 (not found)
		System.out.println(cache);
		cache.put(4, 4); // evicts key 1
		System.out.println(cache);
		cache.get(1); // returns -1 (not found)
		System.out.println(cache);
		cache.get(3); // returns 3
		System.out.println(cache);
		cache.get(4); // returns 4
		System.out.println(cache);
	}

}
