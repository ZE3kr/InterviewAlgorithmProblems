#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(nullptr) {}
};

using namespace std;

class Solution {
  public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode *tmp = head;
		while (tmp && tmp->next) {
			if (tmp->val == tmp->next->val) {
				ListNode *tmp2 = tmp->next->next;
				while (tmp2 && tmp2->val == tmp->val) {
					tmp2 = tmp2->next;
				}
				tmp->next = tmp2;
				tmp = tmp2;
			} else {
				tmp = tmp->next;
			}
		}
		return head;
	}
};
