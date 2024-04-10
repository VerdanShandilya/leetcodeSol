class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        vector<int> v(deck.size(),0);
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        sort(deck.begin(),deck.end());
        int i=0;
        while(!q.empty()){
            v[q.front()]=deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
            i++;
        }
        return v;
    }
};