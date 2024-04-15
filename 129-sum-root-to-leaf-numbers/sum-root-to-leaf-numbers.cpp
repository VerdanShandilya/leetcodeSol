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
    int count=0;
    int ans=0;
    int helper(TreeNode* root,int count){
        if(root!=nullptr){
            count=(count*10)+root->val;
            if(root->left==nullptr && root->right==nullptr){
                // count=(count*10)+root->val;
                ans=ans+count;
            }
            // count=(count*10)+root->val;
            helper(root->left,count);
            helper(root->right,count);
        }
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,count);
    }
};