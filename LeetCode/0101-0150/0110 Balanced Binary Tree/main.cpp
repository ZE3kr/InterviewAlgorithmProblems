#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
	bool isBalanced(TreeNode *root) {
		maxDepth(root);
		return isB(root);
	}
	bool isB(TreeNode *root){
		if (root == nullptr || root->val <=2) {
			return true;
		}
		if (root->left == nullptr || root->right == nullptr) {
			return false;
		}
		if (abs(root->left->val - root->right->val) > 1) {
			return false;
		}
		return isB(root->left) && isB(root->right);
	}
	void maxDepth(TreeNode *root) {
		if (root == nullptr) {
			return;
		}
		if (root->left == nullptr && root->right == nullptr) {
			root->val = 1;
			return;
		}
		if(root->right == nullptr) {
			maxDepth(root->left);
			root->val = root->left->val + 1;
			return;
		}
		if(root->left == nullptr) {
			maxDepth(root->right);
			root->val = root->right->val + 1;
			return;
		}
		maxDepth(root->left);
		maxDepth(root->right);
		root->val = 1 + max(root->left->val, root->right->val);
	}
};
