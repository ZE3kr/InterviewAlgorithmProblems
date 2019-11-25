function TreeNode(val) {
	this.val = val;
	this.left = this.right = null;
}

function invertTree(root) {
	if(root == null) {
		return root;
	}
	var tmp = root.left;
	root.left = root.right;
	root.right = tmp;
	invertTree(root.left);
	invertTree(root.right);
	return root
}
