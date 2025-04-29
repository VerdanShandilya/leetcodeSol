class Solution {
public:
    int candy(vector<int>& ratings){
        int ans=ratings.size();
        int i=1;
        while(i<ratings.size()){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int peak=0;
            while(i<ratings.size() && ratings[i]>ratings[i-1]){
                peak++;
                ans+=peak;
                i++;
            }
            int valley=0;
            while(i<ratings.size() && ratings[i]<ratings[i-1]){
                valley++;
                ans+=valley;
                i++;
            }
            ans-=min(peak,valley);
        }
        return ans;
    }
};