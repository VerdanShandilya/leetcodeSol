class Solution {
public:
    int minBitFlips(int start, int goal) {
        int z=start^goal;
        int ans=0;
        while(z!=0){
            if(z&(1)){
                ans++;
            }
            z=z>>1;
        }
        return ans;
    }
};