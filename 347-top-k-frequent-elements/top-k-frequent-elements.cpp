class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            q.push({i.second,i.first});
            if(q.size()>k){
                q.pop();
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.top();
            v.push_back(p.second);
            q.pop();
        }
        // while(i<k){
        //     pair<int,int> p=q.top();
        //     v.push_back(p.second);
        //     i++;
        //     q.pop();
        // }
        return v;
    }
};