# 0051-0100 心得

## 树

### 0094 Binary Tree Inorder Traversal

中序遍历。非常经典的题目。这道题若要使用递归实现则非常简单，但我尝试使用非递归方式实现。

这道题非常经典，也是数据结构课所讲述的题目之一。我们应该把该算法背下来，也就是：

```cpp
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
```

### 0095 Unique Binary Search Trees II

这道题是要求输出所有可能的，节点值为 1...n 的的二叉搜索树。要求返回所有可能结果的数组。

这道题理论上也可以用动态规划来简化问题，但由于 C++ 的内存管理太复杂，我就没有做实现哈哈。

我的方法是递归，分别设置头节点为 head 的值为 1~n。则头节点的左子树正好可以分别是节点值为 1...head->value-1 的子树的所有可能结果。右子树则为节点值为 head->value+1...n 的子树的所有可能结果。

左子树的生成可以使用递归，右子树则可以先生成 1...n-head->value 的子树，然后再对子树加 head->value。注意由于选择不同的

由于在给头节点的左孩子赋值时没有进行深拷贝，因此返回的树中有公用的节点。但该程序必须在给右孩子赋值时选用深拷贝（亲自采坑）。这个具体需要举例说明：

左侧不需要深拷贝的例子：下面这个图，从 A 节点看是个 BST，从 B 节点看也是 BST。

```
       3 (Node A)
      /
     2   2 (Node B)
    / /     \
    1(reuse)  3
```

但是右侧必须要深拷贝，因为我们需要给右侧复制。考虑我们需要输出一棵节点数为 4 的 BST，那么在创建头没有左孩子，值为 1 的头节点时，我们会使用 A 节点作为头节点的右子树。那么此时我们需要修改右节点的值：

```
     1
      \
       4 (Node A)
      /
     3   2 (Node B)
    / /     \
    2(reuse)  3
```

糟糕！此时节点 B 就不是 BST 了。

因此在给右节点增加数值时，务必要深拷贝：

```cpp
TreeNode *Solution::AddTree(TreeNode *head, int add) {
	TreeNode * newTree = nullptr;
	if(head){
		newTree = new TreeNode(head->val + add);
		newTree->left = AddTree(head->left, add);
		newTree->right = AddTree(head->right, add);
	}
	return newTree;
}
```

行吧，那就暂时先这样。

### 0098 Validate Binary Search Tree

可以用 0094 的 inOrder 后的结果，比较是否严格增。这个算法时间复杂度和空间复杂度都没问题。

也可以用 range 递归，看子树是否符合区间哈哈。
