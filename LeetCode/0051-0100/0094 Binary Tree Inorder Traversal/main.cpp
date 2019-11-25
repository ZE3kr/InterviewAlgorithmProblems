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
 * @See Data Structure
 */
class Solution {
  public:
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode *> stack;
		vector<int> answer;
		TreeNode *p = root;
		while (!stack.empty() || p) {
			while (p) {
				stack.push(p);
				p = p->left;
			}
			p = stack.top();
			stack.pop();
			answer.push_back(p->val);
			p = p->right;
		}
		return answer;
	}
};

int main() {
	cout << "Hello, World!" << std::endl;
	return 0;
}