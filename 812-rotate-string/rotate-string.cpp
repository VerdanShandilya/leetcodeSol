class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        int i=0;
        while(i<goal.size()){
            if(s==goal){
                return true;
            }
            char a=s[0];
            for(int j=0;j<s.size()-1;j++){
                s[j]=s[j+1];
            }
            s[s.size()-1]=a;
            i++;
        }
        return false;
    }
};