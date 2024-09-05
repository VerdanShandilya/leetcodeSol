class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total=n+rolls.size();
        int sum=mean*total;
        for(int i=0;i<rolls.size();i++){
            sum-=rolls[i];
        }
        vector<int> ans;
        if(sum>n*6 || sum/n==0){
            return {};
        }
        int c;
        if(sum%n==0){
            for(int i=0;i<n;i++){
                c=sum/n;
                if(c<0){
                    return {};
                }
                ans.push_back(sum/n);
            }
        }
        else{
            int rem=sum%n;
            for(int i=0;i<n;i++){
                c=sum/n;
                if(c<0)
                return {};
                ans.push_back(sum/n);
            }
            int i=0;
            while(rem!=0){
                ans[i]=ans[i]+1;
                rem=rem-1;
                i++;
            }
        }
        return ans;
    }
};