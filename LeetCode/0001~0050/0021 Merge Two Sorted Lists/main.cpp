#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
};

class Solution {
  public:
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

using namespace std;

int main() {
	Solution s;
	ListNode l1[3];
	ListNode l2[3];
	int list1[3] = {1, 2, 4};
	int list2[3] = {1, 3, 4};
	for (int i = 0; i < 3; ++i) {
		l1[i].val = list1[i];
		l2[i].val = list2[i];
	}
	for (int i = 0; i < 2; ++i) {
		l1[i].next = &l1[i + 1];
		l2[i].next = &l2[i + 1];
	}
	l1[2].next = nullptr;
	l2[2].next = nullptr;

	auto a = s.mergeTwoLists(l1, l2);

	cout << a->val << endl;
	while (a->next != nullptr) {
		a = a->next;
		cout << a->val << endl;
	}
}
