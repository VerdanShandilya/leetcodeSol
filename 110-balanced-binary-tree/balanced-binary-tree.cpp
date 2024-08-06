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
    bool ans=true;
    int helper(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int a=1+helper(root->left);
        int b=1+helper(root->right);
        if(abs(a-b)>1){
            ans=false;
        }
        return max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        helper(root);
        return ans;
    }
};