class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        unordered_map<char,int> m,m1;
        vector<pair<int,char>> w1,w2;
        for(int i=0;i<word1.size();i++){
            m[word1[i]]++;
        }
        for(auto i : m){
            w1.push_back({i.second,i.first});
        }
        for(int i=0;i<word2.size();i++){
            m1[word2[i]]++;
            if(m.find(word2[i])==m.end()){
                return false;
            }
        }
        for(int i=0;i<word2.size();i++){
            m[word2[i]]--;
            if(m[word2[i]]==0){
                m.erase(word2[i]);
            }
        }
        if(m.size()==0){
            return true;
        }
        for(auto i : m1){
            w2.push_back({i.second,i.first});
        }
        if(w1.size()!=w2.size()){
            return false;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        for(int i=0;i<w1.size();i++){
            auto temp=w1[i];
            auto temp1=w2[i];
            if(temp.first!=temp1.first){
                return false;
            }
        }
        return true;
    }
};