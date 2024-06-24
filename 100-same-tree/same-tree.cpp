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
    bool helper(TreeNode* p, TreeNode* q){
        if(p==nullptr && q!=nullptr){
            return false;
        }
        if(p!=nullptr && q==nullptr){
            return false;
        }
        if(p==nullptr && q==nullptr){
            return true;
        }
        if(p->val!=q->val){
            return false;
        }
        bool a=helper(p->left,q->left);
        bool b=helper(p->right,q->right);
        return a&&b;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p,q);
    }
};