struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (!head) {
			return head;
		}
		int all = 0;
		ListNode *tmp = head;
		ListNode *prev = tmp;
		while (tmp) {
			prev = tmp;
			tmp = tmp->next;
			all++;
		}
		prev->next = head;
		tmp = head;
		for (int i = 0; i < all - (k % all); ++i) {
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = nullptr;
		return tmp;
	}
};
