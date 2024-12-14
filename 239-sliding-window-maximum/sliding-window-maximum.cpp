class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int m=INT_MIN;
        int l=0;
        int r=0;
        while(r<nums.size()){
            while(!q.empty() && q.front()<nums[r]){
                q.pop_front();
            }
            while(!q.empty() && q.back()<nums[r]){
                q.pop_back();
            }
            q.push_back(nums[r]);
            if(r-l+1==k){
                ans.push_back(q.front());
                if(q.front()==nums[l]){
                    q.pop_front();
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