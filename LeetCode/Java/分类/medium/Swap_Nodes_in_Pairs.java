package medium;

public class Swap_Nodes_in_Pairs {

	public class ListNode {
	    int val;
	    ListNode next;
	    ListNode(int x) { val = x; }
	}
	
    public ListNode swapPairs(ListNode head) {
    	//返回特殊情况
    	if (head == null)
    		return null;
    	if (head.next == null)
    		return head;
    	//成对交换
    	ListNode newhead = head.next;
    	while (head != null && head.next != null) {
    		ListNode nextnext = head.next.next;
    		head.next.next = head;
    		if (nextnext != null) {
    			if (nextnext.next != null)	//有完整的下一对，指向下一对的第二个
    				head.next = nextnext.next;
    			else						//不完整的下一对，指向下一对的第一个
    				head.next = nextnext;
    		} else {
    			head.next = null;
    		}
    		head = nextnext;
    	}
		return newhead;
    }
    
    public static void print(ListNode head) {
		while (head != null) {
			System.out.print(head.val + " ");
			head = head.next;
		}
	}
	
	public static void main(String[] args) {
		Swap_Nodes_in_Pairs main = new Swap_Nodes_in_Pairs();
		ListNode l1 = main.new ListNode(1);
		ListNode l2 = main.new ListNode(2);
		ListNode l3 = main.new ListNode(3);
//		ListNode l4 = main.new ListNode(4);
//		ListNode l5 = main.new ListNode(5);
//		ListNode l6 = main.new ListNode(6);
		l1.next = l2;
		l2.next = l3;
//		l3.next = l4;
//		l4.next = l5;
//		l5.next = l6;
		print(l1);
		System.out.println();
		ListNode newlist = main.swapPairs(l1);
		print(newlist);
	}

}
