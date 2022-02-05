void deleteTree(TreeNode<int>* root) {
	for (int i = 0; i < root->children.size(); i++) {
		deleteTree(root->children[i]);
	}
	delete root;
}

