class Solution {
public:
    bool swwap(string a,string b){
        string real=a;
        if(a==b){
            return true;
        }
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                swap(a[i],a[j]);
                int z=stoi(a);
                int x=stoi(b);
                if(z==x){
                    return true;
                }
                a=real;
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                string a=to_string(nums[i]);
                string b=to_string(nums[j]);
                if(a.size()>b.size()){
                    if(swwap(a,b)){
                        ans++;
                    }
                }
                else{
                    if(swwap(b,a)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};