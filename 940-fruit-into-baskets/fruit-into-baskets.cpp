class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int unique=0;
        int l=0;
        int r=0;
        int ans=0;
        while(r<fruits.size()){
            m[fruits[r]]++;
            if(m[fruits[r]]==1){
                unique++;
            }
            if(unique>2){
                while(l<r && unique>2){
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0){
                        unique--;
                    }
                    l++;
                }
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};