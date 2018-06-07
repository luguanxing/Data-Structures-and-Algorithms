package easy;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class Remove_Duplicates_from_Sorted_List {

	public class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
		}

		@Override
		public String toString() {
			return "" + val;
		}
	}

	class Solution {
		public ListNode deleteDuplicates(ListNode head) {
			if (head == null) {
				return null;
			}
			Map<Integer, Integer> map = new HashMap<>();
			ListNode cur = head;
			while (cur != null) {
				Integer valTimes = map.get(cur.val);
				if (valTimes == null) {
					map.put(cur.val, 1);
				} else {
					map.put(cur.val, valTimes + 1);
				}
				cur = cur.next;
			}
			List<ListNode> newList = new LinkedList<>();
			cur = head;
			while (cur != null) {
				Integer valTimes = map.get(cur.val);
				if (valTimes != null) {
					newList.add(cur);
					map.remove(cur.val);
				}
				cur = cur.next;
			}
			for (int i = 0; i < newList.size() - 1; i++) {
				newList.get(i).next = newList.get(i + 1);
			}
			newList.get(newList.size() - 1).next = null;
			return newList.get(0);
		}
	}

	public static void main(String[] args) {
		Remove_Duplicates_from_Sorted_List main = new Remove_Duplicates_from_Sorted_List();
		ListNode head = main.new ListNode(1);
		ListNode node_1 = main.new ListNode(1);
		ListNode node_2 = main.new ListNode(2);
		ListNode node_3 = main.new ListNode(3);
		ListNode node_4 = main.new ListNode(3);
		head.next = node_1;
		node_1.next = node_2;
		node_2.next = node_3;
		node_3.next = node_4;
		main.new Solution().deleteDuplicates(head);
	}

}
