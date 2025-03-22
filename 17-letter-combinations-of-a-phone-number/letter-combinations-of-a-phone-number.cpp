class Solution {
public:
    void helper(string *arr,vector<string> &ans,string digits,int index,string a){
        if(index==digits.size()){
            ans.push_back(a);
            return;
        }
        int num=digits[index]-'0';
        for(int i=0;i<arr[num].size();i++){
            helper(arr,ans,digits,index+1,a+arr[num][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()){
            return {};
        }
        string arr[]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        helper(arr,ans,digits,0,"");
        return ans;
    }
};