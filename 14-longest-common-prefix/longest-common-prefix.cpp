class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        int len=INT_MAX;
        for(int i=0;i<strs.size();i++){
            len=min(len,int(strs[i].size()));
        }
        unordered_map<char,int> m;
        string ans="";
        for(int i=0;i<len;i++){
            char ch;
            for(int j=0;j<strs.size();j++){
                ch=strs[j][i];
                m[strs[j][i]]++;
            }
            if(m[ch]==strs.size()){
                ans+=ch;
                m.erase(ch);
            }
            else{
                break;
            }
        }
        return ans;
    }
};