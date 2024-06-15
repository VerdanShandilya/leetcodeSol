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
        int extra=0;
        int sum=0;
        ListNode* ans=l1;
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        while(ans!=nullptr || l2!=nullptr){
            sum=0;
            if(ans!=nullptr){
                sum+=ans->val;
                ans=ans->next;
            }
            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=extra;
            extra=sum/10;
            // ans->val=sum%10;
            ListNode* dummy1=new ListNode(sum%10);
            temp->next=dummy1;
            temp=temp->next;
        }
        if(extra!=0){
            ListNode* dummy2=new ListNode(extra);
            temp->next=dummy2;
        }
        return dummy->next;
    }
};