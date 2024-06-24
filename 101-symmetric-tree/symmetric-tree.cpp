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
    bool helper(TreeNode* root,TreeNode* root1){
        if(root==nullptr && root1!=nullptr){
            return false;
        }
        if(root!=nullptr && root1==nullptr){
            return false;
        }
        if(root==nullptr && root1==nullptr){
            return true;
        }
        if(root->val!=root1->val){
            return false;
        }
        bool a=helper(root->left,root1->right);
        bool b=helper(root->right,root1->left);
        return a&&b;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
};
