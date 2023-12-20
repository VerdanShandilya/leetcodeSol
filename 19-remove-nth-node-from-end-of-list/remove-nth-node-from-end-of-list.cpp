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
        int l=0;
        while(temp!=nullptr){
            l++;
            temp=temp->next;
        }
        if(l==n){
            return head->next;
        }
        ListNode* temp1=head;
        l=l-n;
        int c=1;
        while(c<l){
            temp1=temp1->next;
            c++;
        }
        if(n==1){
            temp1->next=nullptr;
        }
        else{
            temp1->next=temp1->next->next;
        }
        return head;
    }
};