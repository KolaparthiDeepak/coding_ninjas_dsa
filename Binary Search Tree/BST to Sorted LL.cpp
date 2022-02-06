/*Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:

The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   

Output Format:

The first and only line of output prints the elements of sorted linked list.

Constraints:

Time Limit: 1 second

Sample Input 1:

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output 1:

2 5 6 7 8 10
*/

/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
class Pair
{
    public:
    Node<int>* head;
    Node<int>* tail;
};
Pair help(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        Pair ans;
        ans.head=NULL;
        ans.tail=NULL;
        return ans;
    }
    Node<int>* newnode=new Node<int>(root->data);
    Pair leftans=help(root->left);
    Pair rightans=help(root->right);
    Pair ans;
    if(leftans.head==NULL&rightans.head==NULL)
    {
        ans.head=newnode;
        ans.tail=newnode;
    }
    else if(leftans.head!=NULL&&rightans.head==NULL)
    {
        ans.head=leftans.head;
        leftans.tail->next=newnode;
        ans.tail=newnode;
    }
    else if(rightans.head!=NULL&&leftans.head==NULL)
    {
        ans.head=newnode;
        newnode->next=rightans.head;
        ans.tail=rightans.tail;
    }
    else
    {
        ans.head=leftans.head;
        leftans.tail->next=newnode;
        newnode->next=rightans.head;
        ans.tail=rightans.tail;
    }
    return ans;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    return help(root).head;
}

