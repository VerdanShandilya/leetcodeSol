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
    int helper(TreeNode* root,int ans){
        if(root==nullptr){
            return ans;
        }
        int a=helper(root->left,ans+1);
        int b=helper(root->right,ans+1);
        return max(a,b);

    }
    int maxDepth(TreeNode* root) {
        int ans=0;
        return helper(root,ans);
    }
};