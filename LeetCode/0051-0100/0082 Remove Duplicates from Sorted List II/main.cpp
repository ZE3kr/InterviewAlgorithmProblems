#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		auto ans = head;
		while(ans && ans->next && ans->val == ans->next->val){
			int p = head->val;
			while(head && p == head->val){
				auto del = head;
				head = head->next;
				ans = head;
				delete del;
			}
		}

		while(head){
			if (head->next && head->next->next && head->next->val == head->next->next->val){
				int p = head->next->val;
				while (head->next && p == head->next->val) {
					auto del = head->next;
					head->next = head->next->next;
					delete del;
				}
			} else {
				head = head->next;
			}
		}
		return ans;
	}
};

int main() {
	Solution a;

	int array[10] = {1,2,3,3,4,4,5};
	ListNode * list = new ListNode(array[0]);
	ListNode * tmp = list;

	for (int j = 1; j < 7; ++j) {
		tmp->next = new ListNode(array[j]);
		tmp = tmp->next;
	}

	tmp = list;

	while(tmp){
		cout << tmp->val << ' ';
		tmp = tmp->next;
	}
	cout << endl;

	tmp = a.deleteDuplicates(list);

	while(tmp){
		cout <<  tmp->val << ' ';
		tmp = tmp->next;
	}

	return 0;
}