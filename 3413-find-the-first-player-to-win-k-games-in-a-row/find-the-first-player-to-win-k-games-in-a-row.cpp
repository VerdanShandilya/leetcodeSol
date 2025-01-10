class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        unordered_map<int,int> m;
        deque<int> q;
        for(int i=0;i<skills.size();i++){
            q.push_back(i);
        }
        if(k>skills.size()){
            int ans=0;
            for(int i=1;i<skills.size();i++){
                if(skills[i]>skills[ans]){
                    ans=i;
                }
            }
            return ans;
        }
        while(1){
            int temp=q.front();
            q.pop_front();
            int temp2=q.front();
            q.pop_front();
            if(skills[temp]>skills[temp2]){
                m[temp]++;
                if(m[temp]==k)
                return temp;
                q.push_front(temp);
                q.push_back(temp2);
            }
            else{
                m[temp2]++;
                if(m[temp2]==k)
                return temp2;
                q.push_front(temp2);
                q.push_back(temp);
            }
        }
        return 0;
    }
};