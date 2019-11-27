struct ListNode {
	int val;
	ListNode *next;
};

class Solution {
  public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int all = 0;
		auto tmp = head;
		while (tmp != nullptr) {
			tmp = tmp->next;
			all++;
		}
		if (all < 1) {
			return head;
		}
		if (all == 1) {
			return nullptr;
		}
		if (all == n) {
			return head->next;
		}

		int i = 0;
		tmp = head;
		while (tmp != nullptr) {
			i++;
			if (i == all - n) {
				tmp->next = tmp->next->next;
				return head;
			}
			tmp = tmp->next;
		}
	}
};
