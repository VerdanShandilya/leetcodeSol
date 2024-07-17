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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (root == nullptr) return v;
        queue<TreeNode*> s;
        s.push(root);
        s.push(nullptr);
        while(!s.empty()){
            TreeNode* temp=s.front();
            s.pop();
            if(temp!=nullptr){
                TreeNode* temp2=s.front();
                if(temp2==nullptr){
                    v.push_back(temp->val);
                }
                if(temp->left){
                    s.push(temp->left);
                }
                if(temp->right){
                    s.push(temp->right);
                }
            }
            else{
                if(!s.empty()){
                    s.push(nullptr);
                }
            }
        }
        return v;
    }
};

