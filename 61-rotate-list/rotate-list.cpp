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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0){
            return head;
        }
        int len=0;
        ListNode* temp=head;
        ListNode* temp1;
        while(temp!=nullptr){
            temp=temp->next;
            len++;
        }
        // if(len==1 || len==k){
        //     return head;
        // }
        if(k>len){
            k=k%len;
        }
        if(len==1 || len==k || k==0){
            return head;
        }
        len=len-k;
        temp=head;
        for(int i=1;i<len;i++){
            temp=temp->next;
        }
        ListNode* temp2=temp;
        temp1=temp->next;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=head;
        temp2->next=nullptr;
        return temp1;
    }
};