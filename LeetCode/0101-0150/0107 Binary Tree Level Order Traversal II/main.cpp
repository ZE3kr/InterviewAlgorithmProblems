#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		vector<vector<int>> ans;
		lOB(root, 0, ans);
		reverse(ans.begin(), ans.end());
		return ans;
	}
	void lOB(TreeNode *root, int level, vector<vector<int>> &v) {
		if (root == nullptr) {
			return;
		}
		if (v.size() <= level) {
			v.emplace_back(vector<int>(0));
		}
		v[level].push_back(root->val);
		lOB(root->left, level + 1, v);
		lOB(root->right, level + 1, v);
	}
};
