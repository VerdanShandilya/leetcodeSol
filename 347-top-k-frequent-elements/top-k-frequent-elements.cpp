class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        priority_queue<pair<int,int>> q;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            q.push({i.second,i.first});
        }
        int i=0;
        while(i<k){
            pair<int,int> p=q.top();
            v.push_back(p.second);
            i++;
            q.pop();
        }
        return v;
    }
};