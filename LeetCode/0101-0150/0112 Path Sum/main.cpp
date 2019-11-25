using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == nullptr) {
			return false;
		}
		if(root->left && hasPathSum(root->left, sum - root->val)) {
			return true;
		}
		if(root->right && hasPathSum(root->right, sum - root->val)) {
			return true;
		}
		return root->left == nullptr && root->right == nullptr && sum == root->val;
	}
};
