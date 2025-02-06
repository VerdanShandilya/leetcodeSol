class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int prod=nums[i]*nums[j];
                if(m.find(prod)!=m.end()){
                    ans+=(m[prod]*8);
                }
                m[prod]++;
            }
        }
        return ans;
    }
};