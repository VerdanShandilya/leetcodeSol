class Solution {
public:
    vector<string> ans;
    void helper(string a,string digits,string *arr,int i){
        if(i==digits.size()){
            ans.push_back(a);
            return;
        }
        char ch=digits[i];
        string b=arr[ch-'0'];
        for(int j=0;j<b.size();j++){
            helper(a+b[j],digits,arr,i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>a;
        if(digits.size()==0)
            return a;
        string arr[]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper("",digits,arr,0);
        return ans;
    }
};