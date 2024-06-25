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
    vector<int> v;
    void helper(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        isValidBST(root->left);
        v.push_back(root->val);
        isValidBST(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]){
                return false;
            }
        }
        return true;
    }
};