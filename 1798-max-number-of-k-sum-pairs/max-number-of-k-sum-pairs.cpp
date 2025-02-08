class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int diff=k-nums[i];
            if(m.find(diff)!=m.end()){
                m[diff]--;
                if(m[diff]==0){
                    m.erase(diff);
                }
                ans++;
            }
            else{
                m[nums[i]]++;
            }
        }
        return ans;
    }
};