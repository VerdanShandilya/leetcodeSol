class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if(n==1){
            v.push_back(0);
            return v;
        }
        int z=n/2;
        if(n%2!=0){
            v.push_back(0);
        }
        for(int i=1;i<=z;i++){
            v.push_back(i);
            v.push_back(-i);
        }
        return v;
    }
};