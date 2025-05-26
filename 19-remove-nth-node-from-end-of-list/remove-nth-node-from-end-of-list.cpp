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
        if(!head){
            return nullptr;
        }
        int nodes=0;
        ListNode* temp=head;
        while(temp){
            nodes++;
            temp=temp->next;
        }
        int front=nodes-n-1;
        temp=head;
        if(front==-1){
            head=head->next;
            return head;
        }
        while(front){
            temp=temp->next;
            front--;
        }
        temp->next=temp->next->next;
        return head;
    }
};