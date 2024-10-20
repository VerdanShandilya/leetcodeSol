class Solution {
public:
    int strStr(string str, string pat) {
        string temp;
        int i = 0 , j = 0 , n = str.length();
        while(j < n){
            temp.push_back(str[j]);
            if((j-i+1) != pat.length()){
                j++;
            }
            else{
                if(temp.substr(i) == pat){
                    return i;
                }
                i++;
                j++;
            }
        }
        return -1;
    }
};