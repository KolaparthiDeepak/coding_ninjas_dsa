/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :

The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format:

The first and only line of output contains the height of the largest BST.

Constraints:

Time Limit: 1 second

Sample Input 1:

5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:

2
*/

#include<climits>
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
class Ans
{
    public:
    int small;
    int large;
    bool isbst;
    int largeheight;
};
Ans help(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        Ans sol;
        sol.small=INT_MAX;
        sol.large=INT_MIN;
        sol.isbst=true;
        sol.largeheight=0;
        return sol;
    }
    Ans left=help(root->left);
    Ans right=help(root->right);
    Ans sol;
    sol.small=min(root->data,min(left.small,right.small));
    sol.large=max(root->data,max(left.large,right.large));
    sol.isbst=(root->data>left.large)&&(root->data<right.small)&&left.isbst&&right.isbst;
    if(sol.isbst)
        sol.largeheight=1+max(left.largeheight,right.largeheight);
    else
        sol.largeheight=max(left.largeheight,right.largeheight);
    return sol;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    return help(root).largeheight;
}

