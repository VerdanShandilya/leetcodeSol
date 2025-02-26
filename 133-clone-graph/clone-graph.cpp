/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,Node*> vis;
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        queue<Node*> q;
        q.push(node);
        vis[node]= new Node(node->val);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            for(auto i : temp->neighbors){
                if(!vis[i]){
                    vis[i] = new Node(i->val);
                    q.push(i);
                }
                vis[temp]->neighbors.push_back(vis[i]);
            }
        }
        return vis[node];
    }
};