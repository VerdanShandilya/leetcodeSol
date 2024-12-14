class Solution {
public:
    char kthCharacter(int k) {
        string a="a";
        string z="";
        while(a.size()<=k){
            z="";
            for(int i=0;i<a.size();i++){
                if(a[i]=='z'){
                    z=z+'a';
                }
                else{
                z=z+char(a[i]+1);
                }
            }
            a=a+z;
        }
        return a[k-1];
    }
};