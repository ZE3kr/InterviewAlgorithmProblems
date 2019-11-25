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
	int minDepth(TreeNode *root) {
		if (root == nullptr) {
			return 0;
		}
		if (root->left && root->right) {
			return 1 + min(minDepth(root->left), minDepth(root->right));
		}
		return 1 + max(minDepth(root->left), minDepth(root->right));
	}
};
