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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            TreeNode* temp=node.first;
            int x=node.second.first;
            int y=node.second.second;
            m[x][y].insert(temp->val);
            if(temp->left)
            q.push({temp->left,{x-1,y+1}});
            if(temp->right)
            q.push({temp->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for (auto i : m) {
            vector<int> column;
            for (auto j : i.second){
                column.insert(column.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};