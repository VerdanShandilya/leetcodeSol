class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end(),greater<int>());
        int sum=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int c=sum;
        for(int i=0;i<queries.size();i++){
            c=sum;
            for(int j=0;j<nums.size();j++){
                if(c<=queries[i]){
                    ans.push_back(nums.size());
                    break;
                }
                c=c-nums[j];
                if(c<=queries[i]){
                    ans.push_back(nums.size()-j-1);
                    break;
                }
                else if(j==nums.size()-1){
                    ans.push_back(0);
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};