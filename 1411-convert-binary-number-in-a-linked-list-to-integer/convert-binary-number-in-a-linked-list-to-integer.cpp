/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        cnt--;
        int ans=0;
        while(head!=NULL){
            ans+=pow(2,cnt)*head->val;
            head=head->next;
            cnt--;
        }
        // int ans=0;
        // reverse(v.begin(),v.end());
        // for(int i=v.size()-1;i>=0;i--){
        //     ans+=pow(2,i)*v[i];
        // }
        return ans;
    }
};