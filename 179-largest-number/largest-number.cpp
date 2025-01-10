class Solution {
public:
     static bool cmp(string a,string b){
        string x=a+b;
        string y=b+a;
        if(x>y)
        return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(int i=0;i<nums.size();i++){
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(),s.end(),cmp);
        string ans="";
        for(auto i: s){
            ans+=i;
        }
        if(s[0]=="0")
        return "0";
        return ans;
    }
};