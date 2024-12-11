class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0;
        int r=letters.size()-1;
        char ans='/0';
        while(l<=r){
            int mid=l+(r-l)/2;
            if(letters[mid]-'a'<=target-'a'){
                l=mid+1;
            }
            else{
                ans=letters[mid];
                r=mid-1;
            }
        }
        if(ans>='a' && ans<='z')
        return ans;
        return letters[0];
    }
};