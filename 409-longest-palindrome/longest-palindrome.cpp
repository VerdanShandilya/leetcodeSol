class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int ans=0;
        bool z=false;
        for(auto i : m){
            if(i.second%2==0){
                ans+=i.second;
            }
            else if(i.second%2!=0){
                z=true;
                ans+=i.second-1;
            }
        }
        if(z==true){
            return ans+1;
        }
        return ans;
    }
};