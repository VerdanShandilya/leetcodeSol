// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    vector<int> helper(TreeNode* root){
        vector<int> v;
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=nullptr){
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                sum+=temp->val;
            }
            else{
                v.push_back(sum);
                sum=0;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
        }
        return v;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum=helper(root);
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        root->val=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int level=p.second;
            if(level+1>sum.size()-1){
                break;
            }
            int s=sum[level+1];
            int leftval=0;
            if(temp->left){
                leftval=temp->left->val;
                if(temp->right){
                    temp->left->val=s-(temp->left->val+temp->right->val);
                }
                else{
                    temp->left->val=s-(temp->left->val);
                }
                q.push({temp->left,level+1});
            }
            if(temp->right){
                if(temp->left){
                    temp->right->val=s-(leftval+temp->right->val);
                }
                else{
                    temp->right->val=s-(temp->right->val);
                }
                q.push({temp->right,level+1});
            }
        }
        return root;
    }
};

