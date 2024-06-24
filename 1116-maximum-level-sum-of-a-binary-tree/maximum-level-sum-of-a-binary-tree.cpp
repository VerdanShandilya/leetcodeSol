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
    int helper(TreeNode* root,int level){
        int count=0;
        int ans=INT_MIN;
        int sum=0;
        if(root==nullptr){
            return level;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==nullptr){
                count++;
                if(sum>ans){
                    ans=sum;
                    level=count;
                }
                sum=0;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                sum=sum+temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return level;
    }
    int maxLevelSum(TreeNode* root) {
        return helper(root,0);
    }
};