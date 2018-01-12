package medium;
import java.util.LinkedList;

public class Remove_Nth_Node_From_End_of_List {

	public static class ListNode {
		int val;
		ListNode next;
		ListNode(int x) { val = x; }
	}
	
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		ListNode n1 = new ListNode(1);
		ListNode n2 =  new ListNode(2);
		ListNode n3 =  new ListNode(2);
		n1.next = n2;
		n2.next = n3;
		ListNode ret = removeNthFromEnd(n1, 1);
		System.out.println(ret);
	}

    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head;
        ListNode slow = head;
        for(int i = 1; i <= n; i++)    	//fast�ڵ���slow�ڵ�ǰn��
            fast = fast.next;
        if(fast == null)       			//ɾ���˵�һ��
            return head.next;
        while(fast.next != null) {		//��slowָ��Ҫɾ���ڵ�ǰ
            fast =fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;		//ɾ��slow��һ���ڵ�
        return head;
    }
	
//    public static ListNode removeNthFromEnd(ListNode head, int n) {
//    	LinkedList<ListNode> listNodes = new LinkedList<ListNode>();
//    	ListNode now = head;
//    	int len = 0;
//    	while (now != null) {
//    		listNodes.add(now);
//    		now = now.next;
//    		len++;
//    	}
//    	listNodes.remove(len-n);
//    	if (listNodes.size() > 1) {
//	    	for (int i = 1; i < listNodes.size(); i++) {
//	    		listNodes.get(i - 1).next = listNodes.get(i);
//	    	}
//	    	listNodes.get(listNodes.size() - 1).next = null;
//    	} else {
//    		if (listNodes.size() > 0)
//    			listNodes.get(0).next = null;
//    		else
//				return null;
//    	}
//    	head = listNodes.get(0);
//    	return head;
//    }

}
