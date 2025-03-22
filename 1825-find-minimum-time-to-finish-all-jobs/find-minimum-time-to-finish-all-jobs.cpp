class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int>& v,vector<int>& jobs,int index) {
        if (index==jobs.size()){
            int cans=*max_element(v.begin(),v.end());
            if(cans<ans){
                ans=cans;
            }
            return;
        }
        for (int i=0;i<v.size();i++) {
            if(v[i]+jobs[index]>=ans)
            continue;
            v[i]+=jobs[index];
            helper(v,jobs,index+1);
            v[i]-=jobs[index];
            if (v[i] == 0)
            break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        vector<int> v(k,0);
        helper(v,jobs,0);
        return ans;
    }
};
