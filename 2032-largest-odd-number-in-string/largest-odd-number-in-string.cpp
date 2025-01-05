class Solution {
public:
    string largestOddNumber(string nums) {
        string ans="";
        for(int i=nums.size()-1;i>=0;i--){
            int num=(int)nums[i];
            if(num%2!=0){
                ans=nums.substr(0,i+1);
                return ans;
            }
        }
        return ans;
    }
};