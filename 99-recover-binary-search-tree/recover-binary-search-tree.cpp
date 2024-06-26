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
    TreeNode* temp1;
    TreeNode* mistake=nullptr;
    TreeNode* mistakew=nullptr;
    void helper(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        helper(root->left);
        temp1=root;
        if(prev!=nullptr){
            if(temp1->val<prev->val){
                mistake=temp1;
                if(mistakew==nullptr){
                    mistakew=prev;
                }
            }
        }
        prev=temp1;
        helper(root->right);
        return ;
    }
    // void change(TreeNode* root){
    //     if(root==nullptr){
    //         return;
    //     }
    //     if(root->val>mistake->val){
    //         int a=root->val;
    //         root->val=mistake->val;
    //         mistake->val=a;
    //         return;
    //     }
    //     change(root->left);
    //     change(root->right);
    // }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(mistake->val,mistakew->val);
    }
};