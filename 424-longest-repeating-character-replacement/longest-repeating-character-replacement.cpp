class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(char i='A';i<='Z';i++){
            int l=0;
            int r=0;
            int rep=0;
            while(r<s.size()){
                if(s[r]==i){
                    r++;
                }
                else if(s[r]!=i && rep<k){
                    rep++;
                    r++;
                }
                else if(s[l]==i){
                    l++;
                }
                else{
                    l++;rep--;
                }
                ans=max(ans,r-l);
            }
        }
        return ans;
    }
};