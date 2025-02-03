class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<word1.size();i++){
            freq1[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++){
            freq2[word2[i]-'a']++;
        }
        for(int i=0;i<freq1.size();i++){
            if((freq1[i]!=0 && freq2[i]==0) || (freq1[i]==0 && freq2[i]!=0)){
                return false;
            }
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<freq1.size();i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
};