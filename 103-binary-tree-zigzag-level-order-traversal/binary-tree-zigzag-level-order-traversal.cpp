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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        bool a=true;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=nullptr){
                v.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            else{
                if(a){
                    ans.push_back(v);
                }
                else{
                    reverse(v.begin(),v.end());
                    ans.push_back(v);
                }
                v.clear();
                a=!a;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
        }
        return ans;
    }
};