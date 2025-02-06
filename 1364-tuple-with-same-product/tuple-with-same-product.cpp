class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        vector<int> prods;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1;j<nums.size(); j++){
                prods.push_back(nums[i]*nums[j]);
            }
        }
        int ans=0;
        sort(prods.begin(),prods.end());
        int freq=1;
        for(int i=1;i<prods.size();i++){
            if(prods[i]==prods[i-1]){
                freq++;
            }
            else{
                if(freq>1){
                    ans+=freq*(freq-1)*4;
                }
                freq=1;
            }
        }
        if (freq>1) {
            ans+=freq*(freq-1)*4;
        }
        return ans;
    }
};