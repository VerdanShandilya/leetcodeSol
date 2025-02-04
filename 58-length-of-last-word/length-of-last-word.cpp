class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        while(s[i]==' '){
            i--;
        }
        int j=i;
        while(j>=0 && s[j]!=' '){
            j--;
        }
        return abs(i-j);
    }
};