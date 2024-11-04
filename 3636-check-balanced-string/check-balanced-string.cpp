class Solution {
public:
    bool isBalanced(string num) {
        int co=0;
        int ce=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0){
                int temp=num[i]-'0';
                ce+=temp;
            }
            else{
                int temp=num[i]-'0';
                co+=temp;
            }
        }
        return co==ce;
    }
};