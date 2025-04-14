class Solution {
public:
    string smallestPalindrome(string s) {
        string f=s.substr(0,s.size()/2);
        sort(f.begin(),f.end());
        string rev=f;
        reverse(rev.begin(),rev.end());
        if(s.size()%2)
        return f+s[s.size()/2]+rev;
        return f+rev;
    }
};