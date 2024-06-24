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
    bool helper(TreeNode* root, int targetSum,int sum){
        if(root==nullptr){
            return false;
        }
        if(root->left==root->right){
            sum+=root->val;
            if(sum==targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        bool a=helper(root->left,targetSum,sum+root->val);
        bool b=helper(root->right,targetSum,sum+root->val);
        return a || b;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum,0);
    }
};