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
    queue<TreeNode*> q;
    void helper(TreeNode* root){
        if(root==nullptr) return;
        q.push(root);
        helper(root->left);
        helper(root->right);
    }
    void flatten(TreeNode* root) {
        if(root==nullptr || root->left==root->right){
            return;
        }
        helper(root);
        root->left=nullptr;
        q.pop();
        TreeNode* current = root;
        while(!q.empty()){
            current->left=nullptr;
            if(current->left==current->right){
                TreeNode* temp=new TreeNode(q.front()->val);
                current->right=temp;
            }
            else{
                current->right=q.front();
            }
            current=current->right;
            q.pop();
        }
    }
};