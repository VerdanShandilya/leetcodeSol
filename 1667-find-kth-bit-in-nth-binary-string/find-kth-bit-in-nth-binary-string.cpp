class Solution {
public:
    char findKthBit(int n, int k) {
        string a="0";
        for(int i=2;i<=n;i++){
            string z="";
            for(int j=0;j<a.size();j++){
                if(a[j]=='1'){
                    z+="0";
                }
                else{
                    z+="1";
                }
            }
            reverse(z.begin(),z.end());
            a=a+("1"+z);
        }
        return a[k-1];
    }
};