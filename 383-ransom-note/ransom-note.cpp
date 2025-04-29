class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto i : magazine){
            m[i]++;
        }
        for(auto i : ransomNote){
            if(m.find(i)!=m.end()){
                if(m[i]==1){
                    m.erase(i);
                }
                else{
                    m[i]--;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};