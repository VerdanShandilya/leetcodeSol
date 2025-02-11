class Solution {
public:

    string removeOccurrences(string s, string part) {
        int r=0;
        int l=0;
        int win=part.size();
        while(r<s.size()){
            if(r-l+1==win){
                if(s.substr(l,win)==part){
                    s=s.substr(0,l)+s.substr(l+win);
                    r=0;
                    l=0;
                }
                else{
                    l++;
                    r++;
                }
            }
            else{
                r++;
            }
        }
        return s;
    }
};