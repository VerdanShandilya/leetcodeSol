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
int a=0;
int count=0;
    int helper(TreeNode* root,int count){
        if(root!=nullptr){
            count++;
            if(root->left==nullptr && root->right==nullptr){
                a=max(a,count);
            }
            helper(root->left,count);
            helper(root->right,count);
        }
        return a;
    }
    int maxDepth(TreeNode* root) {
        return helper(root,count);
    }
};