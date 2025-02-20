class Solution {
public:
    string helper(unordered_map<string,int> &m,int len,string ans){
        if(len==0){
            if(m.find(ans)==m.end()){
                return ans;
            }
            else{
                return "";
            }
        }
        string one=helper(m,len-1,ans+"1");
        string zero=helper(m,len-1,ans+"0");
        if(!one.empty()){
            return one;
        }
        return zero;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> m;
        int len=nums[0].size();
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        return helper(m,len,"");
    }
};