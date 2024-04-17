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
    // vector<int> v;
    // void check(TreeNode* root){
    //     if(root==nullptr){
    //         return;
    //     }
    //     check(root->left);
    //     v.push_back(root->val);
    //     check(root->right);
    // }
    bool helper(TreeNode* root,TreeNode* root1){
        if(root==nullptr && root1!=nullptr){
            return false;
        }
        if(root!=nullptr && root1==nullptr){
            return false;
        }
        if(root==nullptr && root1==nullptr){
            return true;
        }
        if(root->val!=root1->val){
            return false;
        }
        bool a=helper(root->left,root1->right);
        bool b=helper(root->right,root1->left);
        return a&&b;
    }
    bool isSymmetric(TreeNode* root) {
        // check(root);
        // int a=0;
        // int b=v.size()-1;
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i];
        // }
        // while(a<b){
        //     if(v[a]!=v[b]){
        //         return false;
        //     }
        //     a++;
        //     b--;
        // }
        // return true;
        return helper(root,root);
    }
};