class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int> m;
        int unique=2;
        int l=0;
        int r=0;
        int ans=0;
        while(r<arr.size()){
            m[arr[r]]++;
            if(m[arr[r]]==1){
                while(unique==0){
                    m[arr[l]]--;
                    if(m[arr[l]]==0){
                        unique++;
                    }
                    l++;
                }
                unique--;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};