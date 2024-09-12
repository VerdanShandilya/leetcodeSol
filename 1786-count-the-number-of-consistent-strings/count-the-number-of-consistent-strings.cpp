class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> v(allowed.begin(), allowed.end());
        int flag, count = 0, pos;

        for (auto& it : words) {
            flag = 0;
            for (auto& ch : it) {
                if (v.find(ch) == v.end()) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                count++;
        }
        return count;
    }
};