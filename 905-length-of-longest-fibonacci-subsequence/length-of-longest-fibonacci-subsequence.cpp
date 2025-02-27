class Solution {
public:
    int helper(int i,int j,unordered_map<int,int> &m,vector<int> &arr){
        int count=2;
        while(true){
            int sum = i+j;
            if(m.find(sum)!=m.end()){
                int temp = i ;
                i=j;
                j=sum;
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for( int j=i+1;j<arr.size();j++){
                ans=max(ans,helper(arr[i],arr[j],m,arr));
            }
        }
        return(ans>=3) ? ans : 0;
    }
};