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
    ListNode* swapNodes(ListNode* head, int k) {
        int val1;
        int val2;
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            temp=temp->next;
            cnt++;
        }
        ListNode* temp2=nullptr;
        temp=head;
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
        temp2=temp;
        val1=temp->val;
        temp=head;
        int x=cnt-k;
        for(int i=0;i<x;i++){
            temp=temp->next;
        }
        val2=temp->val;
        temp->val=val1;
        temp2->val=val2;
        return head;
    }
};