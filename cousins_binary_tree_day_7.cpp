/*

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

    1
   / \
  2   3
 /
4


Input: root = [1,2,3,4], x = 4, y = 3
Output: false


*/

//solution


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    void findParentDepth(TreeNode* temp,int x,int y, int lev, int &parX, int &parY, int &levX, int &levY)
    {
        if(!temp)return;
        if(temp->left)
        {
            if(temp->left->val == x)
            {
                parX = temp->val;
                levX = lev + 1;
            }else if(temp->left->val == y)
            {
                parY = temp->val;
                levY = lev + 1;
            }
            
        }
        if(temp->right)
        {
            if(temp->right->val == x)
            {
                parX = temp->val;
                levX = lev + 1;
            }
            else if(temp->right->val == y)
            {
                parY = temp->val;
                levY = lev + 1;
            }
        }
        if(levX!=-1 && levY!=-1)return;
        findParentDepth(temp->left, x, y, lev + 1, parX, parY, levX, levY);
        findParentDepth(temp->right, x, y, lev + 1, parX, parY, levX, levY);
        
    }

    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int parX = 0;
        int parY = 0;
        int levX = -1;
        int levY = -1;
        findParentDepth(root, x, y, 0, parX, parY, levX, levY);
        if((levX == levY) && (parX != parY))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};