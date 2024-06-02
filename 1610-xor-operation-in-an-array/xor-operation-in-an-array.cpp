class Solution {
public:
    int xorOperation(int n, int start) {
        int c=0;
        for(int i=0;i<n;i++){
            int num=(2*i)+start;
            c^=num;
        }
        return c;
    }
};