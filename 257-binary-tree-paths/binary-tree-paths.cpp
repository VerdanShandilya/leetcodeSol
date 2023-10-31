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
    vector<string> v;
    void help(TreeNode* root,string a){
        if(root==nullptr){
            return;
        }
        if(root->left==root->right){
            a+=to_string(root->val);
            v.push_back(a);
            return;
        }
        a=a+to_string(root->val)+"->";
        help(root->left,a);
        help(root->right,a);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        help(root,"");
        return v;
    }
};