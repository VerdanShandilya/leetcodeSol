class Solution {
public:
    long long helper(string &word, int k) {
        long long l = 0, r = 0, con = 0, ans = 0;
        unordered_map<char, int> m;
        int n = word.size();
        while(r < n) {
            if(word[r]=='a' || word[r]=='e' || word[r]=='i' || word[r]=='o' || word[r]=='u') {
                m[word[r]]++;
            } 
            else{
                con++;
            }
            while(con >= k && m.size()==5) {
                ans += (n - r);
                if(word[l]=='a' || word[l]=='e' || word[l]=='i' || word[l]=='o' || word[l]=='u') {
                    m[word[l]]--;
                    if (m[word[l]] == 0) {
                        m.erase(word[l]);
                    }
                } 
                else{
                    con--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k + 1);
    }
};
