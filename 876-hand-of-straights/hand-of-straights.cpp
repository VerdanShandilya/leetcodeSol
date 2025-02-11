class Solution {
public:
    bool helper(vector<int> &hand,int k,int index){
        int count=0;
        int num=hand[index];
        for(int i=index;i<hand.size();i++){
            if(hand[i]==num){
                hand[i]=-1;
                count++;
                num++;
            }
            if(count==k){
                return true;
            }
        }
        return false;
    }
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k!=0){
            return false;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            if(hand[i]==-1){
                continue;
            }
            if(!helper(hand,k,i)){
                return false;
            }
        }
        return true;
    }
};