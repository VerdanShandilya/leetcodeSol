class Solution {
public:
    long long coloredCells(int n) {
        n=n-1;
        return 2LL*n*(2+(n-1))+1;
    }
};