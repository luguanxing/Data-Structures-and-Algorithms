package easy;

public class Remove_Linked_List_Elements {

	public class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
		}
		@Override
		public String toString() {
			return val + "->" + next;
		}
	}

	class Solution {
		public ListNode removeElements(ListNode head, int val) {
			if (head == null) {
				return null;
			}
			ListNode prev = null;
			ListNode cur = head;
			boolean isHead = false;
			ListNode newHead = null;
			while (cur != null) {
				while (cur != null && cur.val == val) {
					cur = cur.next;
					if (prev != null) {
						prev.next = cur;
					}
				}
				prev = cur;
				if (cur != null) {
					cur = cur.next;
				}
				if (!isHead) {
					isHead = true;
					newHead = prev;
				}
			}
			return newHead;
		}
	}
	
	class Solution_Standard {
	    public ListNode removeElements(ListNode head, int val) {
	        ListNode fakeHead = new ListNode(-1);
	        fakeHead.next = head;
	        ListNode cur = fakeHead;
	        while(cur.next!=null){
	            if(cur.next.val==val){
	                cur.next = cur.next.next;
	            }else{
	                cur = cur.next;
	            }
	        }
	        return fakeHead.next;
	    }
	}

	public static void main(String[] args) {
		Remove_Linked_List_Elements main = new Remove_Linked_List_Elements();
		ListNode node1 = main.new ListNode(1);

		main.new Solution().removeElements(node1, 1);
	}

}
