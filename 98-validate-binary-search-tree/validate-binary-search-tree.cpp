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
    TreeNode* prev=nullptr;
    TreeNode* temp;
    bool ans=true;
    void helper(TreeNode* root){
        if(root==nullptr){
            return;
        }
        helper(root->left);
        temp=root;
        if(prev!=nullptr){
            if(temp->val<=prev->val){
                ans=false;
                return;
            }
        }
        prev=root;
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};