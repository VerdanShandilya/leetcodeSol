class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem=1;
        int n=digits.size()-1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]=digits[i]+rem;
            if(digits[i]>9){
                digits[i]=0;
            }
            else{
                rem=0;
                break;
            }
        }
        if(rem){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};