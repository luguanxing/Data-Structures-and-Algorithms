/**
* Definition for singly-linked list.
* struct ListNode {
*		 int val;
*		 ListNode *next;
*		 ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int a[100], cta = 0;
		int b[100], ctb = 0;
		int c[100], ctc = 0;
		int i;
		for (i = 0; i < 100; i++)
			c[i] = a[i] = b[i] = 0;

		while (l1) {
			a[cta] = l1->val;
			cta++;
			if (l1->next)
				l1 = l1->next;
			else
				break;
		}
		while (l2) {
			b[ctb] = l2->val;
			ctb++;
			if (l2->next)
				l2 = l2->next;
			else
				break;
		}
	
		int ct = cta > ctb ? cta : ctb;
		for (i = 0; i < ct; i++) {
			c[i] = c[i] + a[i] + b[i];
			if (c[i] >= 10) {
				c[i] -= 10;
				c[i + 1] += 1;
			}
		}

		if (c[ct])
			ct++;
		i = 1;
		ListNode *l = new ListNode(c[0]);
		ListNode *ll = l;
		while (i < ct) {
			l->next = new ListNode(c[i]);
			l = l->next;
			i++;
		}
		return ll;
	}
};
