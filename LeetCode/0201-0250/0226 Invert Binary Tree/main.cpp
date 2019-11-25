struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

class Solution {
  public:
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
};
