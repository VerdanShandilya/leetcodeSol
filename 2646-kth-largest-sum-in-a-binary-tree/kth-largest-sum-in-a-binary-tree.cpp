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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==nullptr){
            return 0;
        }
        priority_queue<long,vector<long>,greater<long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        long sum=0;
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
                pq.push(sum);
                if(pq.size()>k){
                    pq.pop();
                }
                sum=0;
                if(!q.empty())
                q.push(nullptr);
            }
        }
        if(pq.size()<k){
            return -1;
        }
        long ans=pq.top();
        return ans;
    }
};