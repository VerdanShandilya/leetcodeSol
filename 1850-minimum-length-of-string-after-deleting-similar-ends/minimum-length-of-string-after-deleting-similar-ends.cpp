class Solution {
public:
    int minimumLength(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                while( l<r && s[l]==s[l+1]){
                    l++;
                }
                l++;
                while(r>l && s[r]==s[r-1]){
                    r--;
                }
                r--;
            }
            else{
                break;
            }
        }
        if(l>r){
            return 0;
        }
        return r-l+1;
    }
};