/* For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:

Assume that the Binary Tree contains only unique elements. 

Input Format:

The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

Output Format:

The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:

1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:

7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 

Sample Output 1:

1 
2 3 
4 5 6 7 

Sample Input 2:

6
5 6 2 3 9 10 
2 6 3 9 5 10 

Sample Output 2:

5 
6 10 
2 3 
9 
*/

/***********************************************************
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
BinaryTreeNode<int>* help(int *preorder,int *inorder,int prestart,int preend,int instart,int inend);

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return help(preorder,inorder,0,preLength-1,0,inLength-1);
    
}
BinaryTreeNode<int>* help(int *preorder,int *inorder,int prestart,int preend,int instart,int inend)
{
    if(prestart>preend||instart>inend)
        return NULL;
    int rootdata=preorder[prestart];
    int rootindex=-1;
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==rootdata)
        {
            rootindex=i;
            break;
        }
    }
    
    int leftinstart=instart;
    int leftinend=rootindex-1;
    int leftprestart=prestart+1;
    int leftpreend=leftinend-leftinstart+leftprestart;
    
    int rightinstart=rootindex+1;
    int rightinend=inend;
    int rightprestart=leftpreend+1;
    int rightpreend=preend;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
    root->left=help(preorder,inorder,leftprestart,leftpreend,leftinstart,leftinend);
    root->right=help(preorder,inorder,rightprestart,rightpreend,rightinstart,rightinend);
    return root;
}

