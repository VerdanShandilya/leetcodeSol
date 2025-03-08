class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0;
        int r=0;
        int ans=INT_MAX;
        int cans=0;
        while(r<blocks.size()){
            if(blocks[r]=='W'){
                cans++;
            }
            if(r-l+1==k){
                ans=min(cans,ans);
                if(blocks[l]=='W'){
                    cans--;
                }
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};