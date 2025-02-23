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
    string ans="";
    void helper(TreeNode* root,string s){
        if(!root){
            return;
        }
        if(root->left==root->right){
            s+=char(root->val+'a');
            reverse(s.begin(),s.end());
            if(ans=="" || ans>s){
                ans=s;
            }
            return;
        }
        helper(root->left,s+char(root->val+'a'));
        helper(root->right,s+char(root->val+'a'));
    }
    string smallestFromLeaf(TreeNode* root) {
        helper(root,"");
        return ans;
    }
};