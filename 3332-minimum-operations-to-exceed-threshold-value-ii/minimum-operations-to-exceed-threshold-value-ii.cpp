class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long ,vector<long> ,greater<long>> q;
        int count=0;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        while(q.size()>=2 && q.top()<k){
            long temp=q.top();
            q.pop();
            long temp1=q.top();
            q.pop();
            long temp2=temp*2+temp1;
            q.push(temp2);
            count++;
        }
        return count;
    }
};