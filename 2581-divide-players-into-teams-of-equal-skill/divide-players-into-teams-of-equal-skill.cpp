class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i=0;
        int j=skill.size() - 1;
        long sum=0;
        for(int z=0;z<skill.size();z++) {
            sum+=skill[z];
        }
        long long ex =sum/(skill.size()/2);
        if(sum%(skill.size()/2)!=0) {
            return -1;
        }
        long long ans=0;
        while(i<j) {
            if(ex!=(skill[i]+skill[j])) {
                return -1;
            }
            ans+=(long long)skill[i]*skill[j];
            i++;
            j--;
        }
        return ans;
    }
};
