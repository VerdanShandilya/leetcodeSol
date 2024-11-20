class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        for(auto i : p){
            m[i]++;
        }
        int uniq=m.size();
        int l=0;
        int r=0;
        vector<int> ans;
        while(r<s.size()){

            if(m.find(s[r])!=m.end()){
                m[s[r]]--;
                if(m[s[r]]==0){
                    uniq--;
                }
            }
            if(r-l+1==p.size()){
                if(uniq==0){
                    ans.push_back(r-p.size()+1);
                }
                if(m.find(s[l])!=m.end()){
                    if(m[s[l]]==0){
                        uniq++;
                    }
                    m[s[l]]++;
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