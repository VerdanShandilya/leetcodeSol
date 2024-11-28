class Solution {
public:
    static bool helper(pair<int,int> &a,pair<int,int> &b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> v;
        vector<int> ans;
        for(auto i : m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),helper);
        for(int i=0;i<v.size();i++){
            pair<int,int> p=v[i];
            int temp=p.first;
            int ins=p.second;
            for(int j=0;j<temp;j++){
                ans.push_back(ins);
            }
        }
        return ans;
    }
};