class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' '){
            i++;
        }
        bool nev=false;
        if(s[i]=='-'){
            nev=true;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(s[i]=='0'){
            i++;
        }
        long ans=0;
        while (i<s.size() && s[i] >= '0' && s[i] <= '9') {
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX && nev==false){
                return INT_MAX;
            }
            else if(ans>INT_MAX && nev==true){
                return INT_MIN;
            }
            i++;
        }
        if(nev==true)
        return -1*ans;
        return ans;
    }
};