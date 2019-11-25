struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
	ListNode *partition(ListNode *head, int x) {
		if (head == nullptr) {
			return head;
		}
		ListNode less(0);
		ListNode *lessEnd = &less;
		ListNode greater(0);
		ListNode *greaterEnd = &greater;
		ListNode *tmp = head;
		while (tmp) {
			if (tmp->val < x) {
				lessEnd->next = tmp;
				lessEnd = tmp;
			} else {
				greaterEnd->next = tmp;
				greaterEnd = tmp;
			}
			tmp = tmp->next;
		}
		greaterEnd->next = nullptr;
		lessEnd->next = greater.next;
		return less.next;
	}
};
