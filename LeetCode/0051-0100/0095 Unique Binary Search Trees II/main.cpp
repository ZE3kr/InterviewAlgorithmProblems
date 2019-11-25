#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 基本思路：递归
 * 调整子树的序列，避免与根树重复即可
 */
class Solution {
	TreeNode * AddTree(TreeNode * head, int number);
	vector<TreeNode *> generateTreesRecursive(int n);
  public:
	vector<TreeNode *> generateTrees(int n) {
		if (n==0){
			vector<TreeNode *> ans;
			return ans;
		}
		return generateTreesRecursive(n);
	};
};

TreeNode *Solution::AddTree(TreeNode *head, int add) {
	TreeNode * newTree = nullptr;
	if(head){
		newTree = new TreeNode(head->val + add);
		newTree->left = AddTree(head->left, add);
		newTree->right = AddTree(head->right, add);
	}
	return newTree;
}

vector<TreeNode *> Solution::generateTreesRecursive(int n) {
	vector<TreeNode *> ans;
	if (n == 0) {
		ans.push_back(nullptr);
		return ans;
	}
	for (int i = 0; i < n; ++i) {
		auto left = generateTreesRecursive(i);
		auto right = generateTreesRecursive(n - 1 - i);
		for (int l = 0; l < left.size(); ++l) {
			for (int r = 0; r < right.size(); ++r) {
				auto node = new TreeNode(i+1);
				node->left=left[l];
				node->right = AddTree(right[r], i+1);
				ans.push_back(node);
			}
		}
	}
	return ans;
}

int main() {
	Solution a;
	a.generateTrees(2);
	return 0;
}