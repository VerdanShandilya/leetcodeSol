class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0;
        int cl=0;
        int cr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                cr++;
            }
            else{
                cl++;
            }
            if(cr==cl){
                count++;
                cl=0;
                cr=0;
            }
        }
        return count;
    }
};