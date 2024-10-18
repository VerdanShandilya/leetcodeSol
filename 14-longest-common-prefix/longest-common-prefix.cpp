class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m=INT_MAX;
        for(int i=0;i<strs.size();i++){
            m=min(m,(int)strs[i].size());
        }
        int i=0;
        string ans="";
        bool a=true;
        while(i<m){
            a=true;
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    a=false;
                    break;
                }
            }
            if(a){
                ans+=strs[0][i];
            }
            else{
                break;
            }
            i++;
        }
        return ans;
    }
};