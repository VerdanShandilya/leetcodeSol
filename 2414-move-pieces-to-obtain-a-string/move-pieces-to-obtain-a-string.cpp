class Solution {
public:
    bool canChange(string start, string target) {
        int l=0;
        int r=0;
        while(l<start.size() || r<start.size()){
            while(l<start.size() && start[l]=='_'){
                l++;
            }
            while(r<target.size() && target[r]=='_'){
                r++;
            }
            if(start[l]!=target[r]){
                return false;
            }
            if(start[l]=='L' && l<r){
                return false;
            }
            if(start[l]=='R' & r<l){
                return false;
            }
            l++;
            r++;
        }
        return true;
    }
};