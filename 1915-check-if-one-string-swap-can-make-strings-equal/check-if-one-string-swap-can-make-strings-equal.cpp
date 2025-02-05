class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        int w1=0,w2=0;
        int count=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i] && !w1){
                w1=i;
                count++;
            }
            else if(s1[i]!=s2[i]){
                w2=i;
                count++;
            }
        }
        if(count==2){
            if(s1[w1]==s2[w2] && s1[w2]==s2[w1]){
                return true;
            }
        }
        return s1==s2;
    }
};