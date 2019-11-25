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
 */
class Solution {
  public:
	bool isValidBST(TreeNode *root) {
		if(root == nullptr){
			return true;
		}

		vector<int> inOrder;
		stack<TreeNode *> stk;
		TreeNode *p = root;
		while (!stk.empty() || p) {
			while (p) {
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			stk.pop();
			inOrder.push_back(p->val);
			p = p->right;
		}

		int pre = inOrder[0];
		//cout << pre << ' ';
		for (int i = 1; i < inOrder.size(); ++i) {
			if(inOrder[i] <= pre){
				return false;
			}
			pre = inOrder[i];
			//cout << pre << ' ';
		}
		return true;
	}
};

int main() {
	Solution a;
	a.isValidBST(nullptr);
	return 0;
}