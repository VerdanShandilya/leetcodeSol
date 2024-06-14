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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n){
            return head->next;
        }
        cnt=cnt-n;
        temp=head;
        for(int i=0;i<cnt-1;i++){
            temp=temp->next;
        }
        if(n==1){
            temp->next=nullptr;
        }
        else{
            temp->next=temp->next->next;
        }
        return head;
    }
};