import java.util.ArrayList;
import java.util.List;

public class Merge_Two_Sorted_Lists {

	public static class ListNode {
		 int val;
		 ListNode next;
		 ListNode(int x) { val = x; }
	}
	
	public static void main(String[] args) {
		ListNode n1 = null;
		ListNode n2 = new ListNode(0);
		ListNode ret = mergeTwoLists(n1, n2);
	}

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    	//某条链表为空返回另一条
    	if (l1 == null)
    		return l2;
    	if (l2 == null)
    		return l1;
    	//都不为空向后递归
    	if (l1.val < l2.val) {
    		l1.next = mergeTwoLists(l1.next, l2);
    		return l1;
    	} else {
    		l2.next = mergeTwoLists(l1, l2.next);
    		return l2;
    	}
    }
	
}
