struct ListNode {
	int val;
	ListNode *next;
};

class Solution {
  public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		auto tmp = head->next;

		int all;
		for (all = 0; all < k && tmp; ++all) {
			tmp = tmp->next;
		}

		if (all == k) {
			tmp = head->next;
			ListNode *prev = head;
			ListNode *next;
			for (int i = 1; i < k; ++i) {
				next = tmp->next;
				tmp->next = prev;
				prev = tmp;
				tmp = next;
			}
			head->next = reverseKGroup(tmp, k);
			return prev;
		}
		return head;
	}
};
