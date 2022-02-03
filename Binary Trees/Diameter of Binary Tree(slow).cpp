/*
Diameter of a Binary Tree
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 
For a given Binary Tree of integers, find and return the diameter of the tree.
Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50
Diameter of the given tree is 3. 
Complexity of the code: O(n * h), where n is the number of nodes in the tree, 
and h is the height of the tree.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. 
Since -1 is used as an indication whether the left or right node data exist for root, 
it will not be a part of the node data.
Output Format:
The first and the only line of output will be the diameter of the given input tree.
Input: 
1 2 3 4 5 -1 -1 
6 -1 
-1 7 
8 -1 
-1 9
-1 -1 -1 -1 
Output: 
6
*/

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

int height(BinaryTreeNode<int>* root) {
	if (root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) return 0;
	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}
