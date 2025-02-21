class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(char i='A';i<='Z';i++){
            int l=0;
            int r=0;
            int copy=k;
            while(r<s.size()){
                if(s[r]!=i){
                    copy--;
                }
                while(copy<0){
                    if(s[l]!=i){
                        copy++;
                    }
                    l++;
                }
                ans=max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};