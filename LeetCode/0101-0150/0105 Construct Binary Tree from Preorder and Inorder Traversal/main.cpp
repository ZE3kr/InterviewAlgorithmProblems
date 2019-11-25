class Solution {
  public:
	TreeNode *buildTreeHelper(vector<int> &preorder, int i, int j,
	                          vector<int> &inorder, int m, int n) {
		if (i > j || m > n) {
			return nullptr;
		}
		if (i == j && m == n) {
			return new TreeNode(preorder[i]);
		}
		int parentNum = preorder[i];

		int l;
		for (l = m; l <= n; ++l) {
			if (inorder[l] == parentNum) {
				break;
			}
		}

		auto parent = new TreeNode(parentNum);

        // This method allocate extra memory. And the menory complixity is quite high
		/*vector<int> leftInOrder(i), leftPreOrder(i),
		    rightInOrder(preorder.size() - i - 1),
		    rightPreOrder(preorder.size() - i - 1);
		for (int j = 0; j < l; ++j) {
		    leftPreOrder[j] = preorder[j + 1];
		    leftInOrder[j] = inorder[j];
		}
		for (int j = 0; j < preorder.size() - i - 1; ++j) {
		    rightPreOrder[j] = preorder[j + i + 1];
		    rightInOrder[j] = inorder[j + i + 1];
		}*/

        // The following method uses i, j, m, n instead of allocating new memory, which can save a lot of memory when running.
		auto leftChild = buildTreeHelper(preorder, i + 1, l + i - m, inorder, m, l - 1);
		auto rightChild =
		    buildTreeHelper(preorder, l + 1 + i - m, j, inorder, l + 1, n);
		parent->left = leftChild;
		parent->right = rightChild;
		return parent;
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0,
		                       inorder.size() - 1);
	}
};