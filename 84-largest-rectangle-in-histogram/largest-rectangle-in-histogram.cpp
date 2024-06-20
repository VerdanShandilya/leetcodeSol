class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        stack<int> s1;
        vector<int> l(heights.size());
        vector<int> r(heights.size());
        s.push(-1);
        s1.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            r[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<heights.size();i++){ 
            while(s1.top()!=-1 && heights[s1.top()]>=heights[i]){
                s1.pop();
            }
            l[i]=s1.top();
            s1.push(i);
        }
        int ans=0;
        int area=INT_MIN;
        for(int i=0;i<heights.size();i++){
            if(r[i]==-1){
                r[i]=heights.size();
            }
            area=heights[i]*(r[i] - l[i] -1);
            ans=max(area,ans);
        }
        return ans;
    }
};