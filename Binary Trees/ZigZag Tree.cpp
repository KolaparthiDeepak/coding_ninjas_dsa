/*Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:

The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:

The binary tree is printed level wise, as described in the task. Each level is printed in new line.

Constraints

Time Limit: 1 second

Sample Input :

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :

5
10 6
2 3
9
*/

#include<stack>
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    stack<BinaryTreeNode<int>*> even;
    stack<BinaryTreeNode<int>*> odd;
    even.push(root);
    while(!(even.empty()&&odd.empty()))
    {
        while(!even.empty())
        {
            BinaryTreeNode<int>* top1=even.top();
            even.pop();
            cout<<top1->data<<" ";
            if(top1->left!=NULL)
                odd.push(top1->left);
            if(top1->right!=NULL)
                odd.push(top1->right);
        }
        cout<<endl;
        while(!odd.empty())
        {
            BinaryTreeNode<int>* top2=odd.top();
            odd.pop();
            cout<<top2->data<<" ";
            if(top2->right!=NULL)
                even.push(top2->right);
            if(top2->left!=NULL)
                even.push(top2->left);
        }
        cout<<endl;
    }
}
