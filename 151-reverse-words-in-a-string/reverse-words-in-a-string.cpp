class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;
        int j = s.size() - 1;
        while(i>=0 && s[i] == ' ') {
            i--;
        }
        j = i;
        while (i >= 0){
            if (s[i]==' '){
                ans =ans+s.substr(i+1,j-i)+ " ";
                while (i>=0 && s[i]==' '){
                    i--;
                }
                j=i;
            } else{
                i--;
            }
        }
        if (j >= 0){
            ans=ans+s.substr(0, j + 1);
        }
        if (!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};
