class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        int ans=0;
        int count=0;
        for(int i=0;i<=n;i++){
            count=0;
            for(int j=0;j<=31;j++){
                int mask=(1<<j);
                if((i&mask)!=0){
                    count++;
                }
            }
            v.push_back(count);
        }
        return v;
    }
};