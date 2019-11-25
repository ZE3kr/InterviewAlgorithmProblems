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
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		auto ans = pathSumReverse(root, sum);
		for (auto &k : ans) {
			reverse(k.begin(), k.end());
		}
		return ans;
	}
  private:
	vector<vector<int>> pathSumReverse(TreeNode *root, int sum) {
		vector<vector<int>> ans;
		vector<int> empty;
		if (root == nullptr) {
			return ans;
		}
		if (root->left) {
			auto next = pathSumReverse(root->left, sum - root->val);
			if (!next.empty()) {
				for (auto &k : next) {
					k.push_back(root->val);
				}
			}
			ans.insert(ans.end(), next.begin(), next.end());
		}
		if (root->right) {
			auto next = pathSumReverse(root->right, sum - root->val);
			if (!next.empty()) {
				for (auto &k : next) {
					k.push_back(root->val);
				}
			}
			ans.insert(ans.end(), next.begin(), next.end());
		}
		if (root->left == nullptr && root->right == nullptr &&
		    sum == root->val) {
			empty.push_back(root->val);
			ans.push_back(empty);
		}
		return ans;
	}
};
