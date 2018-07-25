package medium;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Remove_Duplicates_from_Sorted_List_II {

	public class ListNode {
	    int val;
	    ListNode next;
	    ListNode(int x) { val = x; }
	    @Override
	    public String toString() {
	    	return "" + val + next;
	    }
	}

	class Solution {
	    public ListNode deleteDuplicates(ListNode head) {
	        Map<Integer, Integer> map = new HashMap<>();
	        List<ListNode> list = new ArrayList<>();
	        ListNode p = head;
	        while (p != null) {
	        	Integer count = map.get(p.val);
	        	if (count == null) {
	        		map.put(p.val, 1);
	        	} else {
	        		map.put(p.val, count + 1);
	        	}
	        	p = p.next;
	        }
	        p = head;
	        while (p != null) {
	        	Integer count = map.get(p.val);
	        	if (count == 1) {
	        		list.add(p);
	        	}
	        	p = p.next;
	        }
	        for (int i = 0; i < list.size() - 1; i++) {
	        	list.get(i).next = list.get(i + 1);
	        }
	        if (!list.isEmpty()) {
	        	list.get(list.size() - 1).next = null;
	        	return list.get(0);
	        } else {
				return null;
			}
	    }
	}
	
	public static void main(String[] args) {
		Remove_Duplicates_from_Sorted_List_II main = new Remove_Duplicates_from_Sorted_List_II();
		ListNode node1 = main.new ListNode(1);
		ListNode node2 = main.new ListNode(1);
		node1.next = node2;
		System.out.println(main.new Solution().deleteDuplicates(null));
	}
	
}
