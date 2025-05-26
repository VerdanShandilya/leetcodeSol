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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        ListNode* dummy= new ListNode(0);
        ListNode* ans=dummy;
        int rem=0;
        while(l2 && l1){
            int value=l1->val+l2->val+rem;
            ListNode* temp=new ListNode();
            dummy->next=temp;
            temp->val=(value%10);
            rem=value/10;
            l2=l2->next;
            l1=l1->next;
            dummy=dummy->next;
        }
        while(l1){
            int value=l1->val+rem;
            ListNode* temp=new ListNode();
            dummy->next=temp;
            temp->val=(value%10);
            rem=value/10;
            l1=l1->next;
            dummy=dummy->next;
        }
        while(l2){
            int value=l2->val+rem;
            ListNode* temp=new ListNode();
            dummy->next=temp;
            temp->val=(value%10);
            rem=value/10;
            l2=l2->next;
            dummy=dummy->next;
        }
        if(rem){
            ListNode* temp=new ListNode();
            dummy->next=temp;
            temp->val=(rem);
        }
        return ans->next;
    }
};