#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	//返回特殊情况
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head; 
	//成对交换
	ListNode* newhead = head->next;
	while (head != NULL && head->next != NULL) {
		ListNode* nextnext = head->next->next;
		head->next->next = head;
		if (nextnext != NULL) {
			if (nextnext->next != NULL)			//有完整的下一对，指向下一对的第二个
				head->next = nextnext->next;
			else												//不完整的下一对，指向下一对的第一个
				head->next = nextnext;
		} else {
			head->next = NULL;
		}
		head = nextnext;
	}
	return newhead;
}

void print(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	print(l1);
	ListNode *ret = swapPairs(l1);
	print(ret);
	return 0;
}