class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        bool ans=true;
        while(j<str2.size()){
            if(i>=str1.size()){
                return false;
            }
            if(str1[i]==str2[j] || str1[i]+1==str2[j]){
                i++;
                j++;
            }
            else if(str1[i]=='z' && str2[j]=='a'){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};