class Solution {
public:
    vector<string> ans;
    void helper(string digits,int i,string a,string *arr){
        if(i==digits.size()){
            ans.push_back(a);
            return;
        }
        char ch=digits[i];
        string b=arr[ch-'0'];
        for(int j=0;j<b.size();j++){
            helper(digits,i+1,a+b[j],arr);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>a;
        if(digits.size()==0)
            return a;
        string arr[]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits,0,"",arr);
        return ans;
    }
};