/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr){
            return nullptr;
        }
        if(root==p){
            return root;
        }
        if(root==q){
            return q;
        }
        TreeNode* l=helper(root->left,p,q);
        TreeNode* r=helper(root->right,p,q);
        if(l!=nullptr && r!=nullptr){
            return root;
        }
        if(l!=nullptr){
            return l;
        }
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};