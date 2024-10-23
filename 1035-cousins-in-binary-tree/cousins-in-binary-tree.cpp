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
    TreeNode* p1=nullptr;
    TreeNode* p2=nullptr;
    int d1;
    int d2;
    void helper(TreeNode* root, int x,int depth){
        if(!root){
            return;
        }
        if(root->left){
            if(root->left->val==x){
                p1=root;
                d1=depth;
                return;
            }
        }
        if(root->right){
            if(root->right->val==x){
                p1=root;
                d1=depth;
                return;
            }
        }
        helper(root->left,x,depth+1);
        helper(root->right,x,depth+1);
    }
    void helper1(TreeNode* root, int y,int depth){
        if(!root){
            return;
        }
        if(root->left){
            if(root->left->val==y){
                p2=root;
                d2=depth;
                return;
            }
        }
        if(root->right){
            if(root->right->val==y){
                p2=root;
                d2=depth;
                return;
            }
        }
        helper1(root->left,y,depth+1);
        helper1(root->right,y,depth+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y){
            return 0;
        }
        helper(root,x,0);
        helper1(root,y,0);
        if(p1!=p2 && d1==d2)
        return 1;
        return 0;
    }
};