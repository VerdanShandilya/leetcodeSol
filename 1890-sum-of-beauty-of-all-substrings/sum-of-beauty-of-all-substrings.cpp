// class Solution {
// public:
//     int beautySum(string s) {
//         if(s.size()<2){
//             return 0;
//         }
//         vector<int> v(26,0);
//         int i=0;
//         int j=0;
//         int ans=0;
//         while(i<s.size()){
//             if(j>=s.size()){
//                 v[s[i]-'a']--;
//                 i++;
//             }
//             else{
//                 v[s[j]-'a']++;
//                 j++;
//             }
//             int maax=0;
//             int miin=s.size();
//             for(int z=0;z<v.size();z++){
//                 if(v[z]>0){
//                     maax=max(maax,v[z]);
//                     miin=min(miin,v[z]);
//                 }
//             }
//             ans=ans+(maax-miin);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int beautySum(string s) {
        int ans =0;
        for (int i=0;i<s.size();i++) {
            vector<int> v(26, 0);
            for (int j=i;j<s.size();j++) {
                v[s[j]-'a']++;
                int maax=0;
                int miin=s.size();
                for (int z=0;z<26;z++) {
                    if (v[z] > 0) {
                        maax=max(maax,v[z]);
                        miin=min(miin,v[z]);
                    }
                }
                ans+=(maax-miin);
            }
        }
        return ans;
    }
};
