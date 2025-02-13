class Solution {
public:
    int helper(string word,int k){
        unordered_map<char,int> m;
        unordered_map<char,int> vowels;
        vowels['a']=0;
        vowels['e']=0;
        vowels['i']=0;
        vowels['o']=0;
        vowels['u']=0;
        int ans=0;
        int l=0;
        int r=0;
        while(r<word.size()){
            if(vowels.find(word[r])==vowels.end()){
                m.clear();
                r++;
                l=r;
                continue;
            }
            m[word[r]]++;
            while(m.size()>k){
                m[word[l]]--;
                if(m[word[l]]==0)
                m.erase(word[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int countVowelSubstrings(string word) {
        return helper(word,5)-helper(word,4);
    }
};