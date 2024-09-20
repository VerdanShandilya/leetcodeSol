// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         int n=s.length()-1;
//         int i=0;
//         int j=n;
//         string a=s;
//         while(i<=j){
//             if(s[i]!=s[j]){
//                 s=s.substr(0,i)+s[j]+s.substr(i);
//                 j++;
//             }
//             i++;
//             j--;
//         }
//         j=n;
//         int z=s.length()-a.length();
//         if(s[z]!=a[0]){
//             s=s.substr(0,z+1)+a[0]+s.substr(z+1);
//         }
//         return s;
//     }
// };

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;
        vector<int> lps(new_s.size(), 0);
        for (int i = 1; i < new_s.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];
            }
            if (new_s[i] == new_s[j]) {
                j++;
            }
            lps[i] = j;
        }
        return rev_s.substr(0, s.size() - lps.back()) + s;
    }
};
