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
    bool helper(TreeNode* root,int s,int count){
        if(root==nullptr){
            return 0;
        }
        if(root->right==nullptr && root->left==nullptr){
            count+=root->val;
            return count==s;
        }
        count+=root->val;
        bool a=helper(root->left,s,count);
        bool b=helper(root->right,s,count);
        return a || b;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return root;
        }
        return helper(root,targetSum,count);
    }
};