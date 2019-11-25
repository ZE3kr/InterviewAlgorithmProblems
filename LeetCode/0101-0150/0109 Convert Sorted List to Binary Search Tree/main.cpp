#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		return sATBST(nums, 0, (int)nums.size());
	}
	TreeNode *sATBST(vector<int> &nums, int lower, int upper) {
		if (lower == upper) {
			return nullptr;
		}
		auto *root = new TreeNode(nums[(lower + upper) / 2]);
		root->left = sATBST(nums, lower, (lower + upper) / 2);
		root->right = sATBST(nums, (lower + upper) / 2 + 1, upper);
		return root;
	}
	TreeNode *sortedListToBST(ListNode *head) {
		vector<int> newArray;
		ListNode *tmp = head;
		while (tmp != nullptr) {
			newArray.push_back(tmp->val);
			tmp = tmp->next;
		}
		return sortedArrayToBST(newArray);
	}
};
