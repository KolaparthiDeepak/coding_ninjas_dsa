/*Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :

The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :

The first and only line of output contains either true or false.

Constraints :

Time Limit: 1 second

Sample Input 1 :

3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :

true

Sample Input 2 :

5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :

false
*/

#include<climits>
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
class IsBSTReturn {
	public:
		bool isBST;
		int minimum;
		int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	IsBSTReturn leftOutput = isBST2(root->left);
	IsBSTReturn rightOutput = isBST2(root->right);
	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
		leftOutput.isBST && rightOutput.isBST;
	IsBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
	return output;
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL||(root->left==NULL&&root->right==NULL))
        return true;
    IsBSTReturn ans=isBST2(root);
    return ans.isBST;
}

