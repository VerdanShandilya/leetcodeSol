class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int count=1;
        for(int i=0;i<word.size()-1;i++){
            if(word[i]==word[i+1]){
                count++;
                if(count>9){
                    string a=to_string(--count);
                    ans+=(a+word[i]);
                    count=1;
                }
            }
            else{
                if(count!=0){
                    string a=to_string(count);
                    ans+=(a+word[i]);
                    count=1;
                }
            }
        }
        if(count!=0){
            string a=to_string(count);
            ans+=(a+word[word.size()-1]);
        }
        return ans;
    }
};