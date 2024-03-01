class Solution {
public:
    vector<int> findWordsContaining(vector<string>& v, char x) {
        vector<int>ans;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            for(auto j:v[i])
            {
                if(j==x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};