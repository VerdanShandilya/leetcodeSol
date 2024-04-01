class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==1){
            return 1;
        }
        int i=s.length()-1;
        int count=0;
        while(!isalpha(s[i])){
            i--;
        }
        while(s[i]!=' '){
            count++;
            i--;
            if(i<0){
                return count;
            }
        }
        return count;
    }
};