struct ListNode {
	int val;
	ListNode *next;
};

class Solution {
  public:
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr) {
			return head;
		}
		auto ans = head->next;
		if (ans == nullptr) {
			return head;
		}
		auto tmp = head;
		auto prev = head;
		ListNode *next;
		bool odd = false;
		while (tmp != nullptr) {
			next = tmp->next;
			odd = !odd;
			if (odd) {
				if (tmp->next) {
					if (tmp->next->next) {
						if (tmp->next->next->next) {
							tmp->next = tmp->next->next->next;
						} else {
							tmp->next = tmp->next->next;
						}
					} else {
						tmp->next = nullptr;
					}
				}
			} else {
				tmp->next = prev;
			}
			prev = tmp;
			tmp = next;
		}
		return ans;
	}
};
