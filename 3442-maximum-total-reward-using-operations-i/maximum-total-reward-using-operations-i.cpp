
class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        sort(reward.begin(), reward.end());
        unordered_set<int> validSums;
        validSums.insert(0);
        int maxReward = 0;
        for(int r : reward) {
            vector<int> toAdd;
            for(int currentSum : validSums) {
                if(currentSum < r) {
                    toAdd.push_back(currentSum + r);
                    maxReward = max(maxReward, currentSum + r);
                }
            }
            for(int newSum : toAdd) {
                validSums.insert(newSum);
            }
        }
        return maxReward;
    }
};
