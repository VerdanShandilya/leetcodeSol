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
TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val){
            ans=p;
            return p;
        }
        if(root->val==q->val){
            ans=q;
            return q;
        }
        if((p->val<root->val && q->val>root->val) || p->val>root->val && q->val<root->val){
            ans=root;
            return root;
        }
        else if(p->val<root->val && q->val<root->val){
            lowestCommonAncestor(root->left,p,q);
        }
        else{
            lowestCommonAncestor(root->right,p,q);
        }
        return ans;
    }
};