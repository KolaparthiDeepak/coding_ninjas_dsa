/*Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :

The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :

The first and only line of output contains data of the node with second largest data.

Constraints:

Time Limit: 1 sec

Sample Input 1 :

10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1 :

40
*/

#include<queue>
#include<vector>
/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
class helper 
{
  public :
    TreeNode<int>* max;
    TreeNode<int>* smax;
    helper(TreeNode<int>* max,TreeNode<int>* smax) 
    {
        this->max=max;
        this->smax=smax;
    }
};
helper help(TreeNode<int> *root);

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
        return NULL;
    helper ans=help(root);
    return ans.smax;
}
helper help(TreeNode<int> *root)
{
    if(root==NULL)
    {
        helper ans(NULL,NULL);
        return ans; 
    }
    helper ans(root,NULL);
    for(int i=0;i<root->children.size();i++)
    {
        helper child=help(root->children[i]);
        if(child.max->data>ans.max->data)
        {
            if(child.smax==NULL)
            {
                ans.smax=ans.max;
                ans.max=child.max;
            }
            else
            {
                if(child.smax->data>ans.max->data)
                {
                    ans.max=child.max;
                    ans.smax=child.smax;
                }
                else
                {
                    ans.smax=ans.max;
                    ans.max=child.max;
                }
            }
        }
        else 
        {
            if(ans.max->data!=child.max->data&&(ans.smax==NULL||child.max->data>ans.smax->data))
            {
                ans.smax=child.max;
            }
        }
    }
    return ans;
}

