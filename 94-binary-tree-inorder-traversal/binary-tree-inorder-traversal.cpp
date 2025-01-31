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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        stack<pair<TreeNode*,int>> s;
        s.push({root,0});
        while(!s.empty()){
            auto temp=s.top();
            s.pop();
            auto add=temp.first;
            int flag=temp.second;
            if(flag==1){
                ans.push_back(add->val);
                continue;
            }
            if(add->left){
                s.push({add->left,0});
            }
            if(flag==0){
                s.push({add,1});
            }
            if(add->right){
                s.push({add->right,0});
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};