class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        if(m==0){
            nums1=nums2;
            return;
        }
        vector<int> temp=nums1;
        int l=0;
        int r=0;
        int i=0;
        while(l<m && r<n && i<n+m){
            if(temp[l]>nums2[r]){
                nums1[i]=nums2[r];
                r++;
            }
            else{
                nums1[i]=temp[l];
                l++;
            }
            i++;
        }
        if(l<m){
            while(l<m){
                nums1[i]=temp[l];
                l++;
                i++;
            }
        }
        if(r<n){
            while(r<n){
                nums1[i]=nums2[r];r++;
                i++;
            }
        }
    }
};