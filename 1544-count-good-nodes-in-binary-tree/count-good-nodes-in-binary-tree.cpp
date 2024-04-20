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
    int ans=0;
    void helper(TreeNode* root,int m){
        if(root==nullptr){
            return ;
        }
        if(root->val>=m){
            ans++;
        }
        helper(root->left,max(m,root->val));
        helper(root->right,max(m,root->val));
        return ;
    }
    int goodNodes(TreeNode* root) {
        helper(root,INT_MIN);
        return ans;
    }
};