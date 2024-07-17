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
        if(p->val==root->val){
            ans=p;
            return ans;
        }
        if(q->val==root->val){
            ans=q;
            return ans;
        }
        if((p->val>root->val && q->val<root->val) || (p->val<root->val && q->val>root->val)){
            ans=root;
            return ans;
        }
        else if(q->val>root->val && p->val>root->val){
            lowestCommonAncestor(root->right,p,q);
        }
        else{
            lowestCommonAncestor(root->left,p,q);
        }
        return ans;
    }
};