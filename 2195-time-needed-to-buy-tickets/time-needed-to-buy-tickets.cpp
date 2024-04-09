class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count=0;
        for(int i=0;i<tickets.size();i++){
            if(tickets[i]<tickets[k]){
                count+=tickets[i];
            }
            else if(i>k){
                count+=tickets[k]-1;
            }
            else{
                count+=tickets[k];
            }
        }
        return count;
    }
};