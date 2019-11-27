#include <vector>

struct ListNode {
	int val;
	ListNode *next;
};

using namespace std;

class Solution {
  public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *ans = nullptr;
		while (!lists.empty()) {
			ans = mergeTwoLists(ans, lists.back());
			lists.pop_back();
		}
		return ans;
	}
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr) {
			return l2;
		}
		if (l2 == nullptr) {
			return l1;
		}
		if (l1->val > l2->val) {
			return mergeTwoLists(l2, l1);
		}
		if (l1->next == nullptr) {
			l1->next = l2;
			return l1;
		}
		if (l1->next->val > l2->val) {
			auto tmp = l1->next;
			l1->next = l2;
			mergeTwoLists(l2, tmp);
			return l1;
		} else {
			mergeTwoLists(l1->next, l2);
			return l1;
		}
	}
};
