using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if((p == nullptr) != (q == nullptr)) {
			return false;
		}
		if((p == nullptr) && (q == nullptr)) {
			return true;
		}
		if(p->val == q->val) {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		} else {
			return false;
		}
	}
	struct TreeNode *invertTree(struct TreeNode *root) {
		if (root == nullptr) {
			return root;
		}
		invertTree(root->left);
		invertTree(root->right);
		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		return root;
	}
	struct TreeNode * copyTree(TreeNode* root) {
		if(root == nullptr) {
			return nullptr;
		}
		auto *ans = new TreeNode(root->val);
		ans->left = copyTree(root->left);
		ans->right = copyTree(root->right);
		return ans;
	}
	bool isSymmetric(TreeNode* root) {
		auto copy = copyTree(root);
		invertTree(copy);
		return isSameTree(copy, root);
	}
};
