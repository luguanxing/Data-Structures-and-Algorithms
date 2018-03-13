package easy;

import java.util.ArrayList;
import java.util.List;

public class Reverse_Linked_List {

	public class ListNode {
		 int val;
		 ListNode next;
		 ListNode(int x) { val = x; }
		@Override
		public String toString() {
			return "[" + val + "], " + next;
		}
	}

	class Solution {
		//使用递归方式
	    public ListNode reverseList(ListNode head) {
	    	if (head == null) {
	    		return null;
	    	}
	    	if (head.next == null) {
	    		return head;
	    	}
	    	
	    	ListNode newHead = reverseList(head.next);
	    	head.next.next = head;
	    	head.next = null;

	    	return newHead;
	    }
		
		//常规法，逐个替换
	    public ListNode reverseList_iteratively(ListNode head) {
	        if (head == null || head.next == null) {
	        	return head;
	        }
	        ListNode pre = head;
	        ListNode cur = pre.next;
	        ListNode next = cur.next;
	        head.next = null;
	        while (cur != null) {
	        	cur.next = pre;
	        	pre = cur;
	        	cur = next;
	        	if (next != null)
	        		next = next.next;
	        }
	    	return pre;
	    }
		
	    //使用list一次排序，比较慢，注意处理head.next
	    public ListNode reverseList_list(ListNode head) {
	        if (head == null) {
	        	return null;
	        }
	        List<ListNode> list = new ArrayList();
	        ListNode p = head;
	        while (p != null) {
	        	list.add(p);
	        	p = p.next;
	        }
	        for (int i = 1; i < list.size(); i++) {
	        	list.get(i).next = list.get(i-1);
	        }
	        head.next = null;
	    	return list.get(list.size()-1);
	    }
	}
	
	public static void main(String[] args) {
		Reverse_Linked_List main = new Reverse_Linked_List();
		ListNode node1 = main.new ListNode(1);
		ListNode node2 = main.new ListNode(2);
		ListNode node3 = main.new ListNode(3);
		node1.next = node2;
		node2.next = node3;
		ListNode result = main.new Solution().reverseList(node1);
		System.out.println(result);
	}
	
}
