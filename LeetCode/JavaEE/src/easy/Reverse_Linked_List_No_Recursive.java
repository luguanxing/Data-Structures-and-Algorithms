package easy;

public class Reverse_Linked_List_No_Recursive {

	public class ListNode {
	    int val;
	    ListNode next;
	    ListNode(int x) { val = x; }
	}
	
	class Solution {
		public ListNode reverseList(ListNode head) {
			if (head == null) {
				return null;
			}
			ListNode newHead = null;
			ListNode curNode = head;
			ListNode prevNode = null;
			while (curNode != null) {
				ListNode nextNode = curNode.next;
				if (nextNode == null) {
					newHead = curNode;
				}
				curNode.next = prevNode;
				prevNode = curNode;
				curNode = nextNode;
			}
			return newHead;
		}
	}

}
