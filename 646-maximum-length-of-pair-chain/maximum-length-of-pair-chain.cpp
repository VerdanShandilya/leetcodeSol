class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),sortcol);
        int ans=0;
        int cur=INT_MIN;
        for(int i=0;i<pairs.size();i++){
            if(cur<pairs[i][0]){
                ans++;
                cur=pairs[i][1];
            }  
        }
        return ans;
    }
};