class Solution {
public:
    int countVowelSubstrings(string word) {
        int a,e,i,o,u;
        a=e=i=o=u=0;
        int cons=0;
        int ans=0;
        for(int z=0;z<word.size();z++){
            a=e=i=o=u=cons=0;
            for(int j=z;j<word.size();j++){
                if(word[j]=='a')
                a++;
                else if(word[j]=='e')
                e++;
                else if(word[j]=='i')
                i++;
                else if(word[j]=='o')
                o++;
                else if(word[j]=='u')
                u++;
                else
                break;
                if(a>0 && e>0 && i>0 && o>0 && u>0){
                    ans++;
                }
            }
        }
        return ans;
    }
};