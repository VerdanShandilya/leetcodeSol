class Solution {
public:
    bool isPalindrome(int x) {
        string y=to_string(x);
        int left=0;
        int right=y.size()-1;
        while(left<right){
            if(y[left]!=y[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};