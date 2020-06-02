/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

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
    vector<int> value;
public:
    
    void inOrder(TreeNode* root)
    {
        if(root == NULL){
            return;
        }
        inOrder(root->left);
        value.push_back(root->val);
        inOrder(root->right);        
                
    }
    int kthSmallest(TreeNode* root,int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        inOrder(root);
        return value[k-1];
    }
};