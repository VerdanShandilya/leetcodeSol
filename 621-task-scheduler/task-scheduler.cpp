class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> p;
        unordered_map<char,int> m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto i : m){
            p.push(i.second);
        }
        int time=0;
        while(!p.empty()){
            vector<int> remain;
            int count=0;
            while(count<=n && !p.empty()){
                int temp=p.top();
                if(temp>1){
                    remain.push_back(temp-1);
                }
                p.pop();
                count++;
                time++;
            }
            for(auto i : remain){
                p.push(i);
            }
            if(p.empty()) break;
            time+=(n+1-count);
        }
        return time;
    }
};