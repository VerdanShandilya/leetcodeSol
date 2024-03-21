class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            int left=0;
            int right=words[i].size()-1;
            if(words[i].size()==1){
                    return words[i];
                }
            while(left<right){
                if(words[i][left]!=words[i][right]){
                    break;
                }
                if(right-left<=2){
                    return words[i];
                }
                left++;
                right--;
            }
        }
        return "";
    }
};