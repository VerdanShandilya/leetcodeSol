class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        return false;
        vector<int> v(26,0);
        vector<int> v1(26,0);
        for(int i=0;i<s1.size();i++){
            v[s1[i]-'a']++;
            v1[s2[i]-'a']++;
        }
        for(int i=0;i<s2.size()-s1.size();i++){
            if(v==v1)
            return true;
            v1[s2[i]-'a']--;
            v1[s2[i+s1.size()]-'a']++;
        }
        return v==v1;
    }
};