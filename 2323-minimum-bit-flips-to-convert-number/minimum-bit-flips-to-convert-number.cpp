class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        int ans=start^goal;
        while(ans){
            if(ans&1)
            count++;
            ans=ans>>1;
        }
        return count;
    }
};