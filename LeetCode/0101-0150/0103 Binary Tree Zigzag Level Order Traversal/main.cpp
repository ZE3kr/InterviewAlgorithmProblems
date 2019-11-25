#include <vector>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		lO(root, 0, ans);
		for (int i = 1; i < ans.size(); i+=2) {
			reverse(ans[i].begin(), ans[i].end());
		}
		return ans;
	}
	void lO(TreeNode* root, int level, vector<vector<int>> &v){
		if(root == nullptr) {
			return;
		}
		if(v.size() <= level) {
			v.emplace_back(vector<int>(0));
		}
		v[level].push_back(root->val);
		lO(root->left, level+1, v);
		lO(root->right, level+1, v);
	}
};
