class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i : nums){
            m[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
        for(auto i : m){
            q.push({i.second,i.first});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto temp=q.top();
            ans.push_back(temp.second);
            q.pop();
        }
        return ans;
    }
};