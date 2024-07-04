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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp2=head;
        int sum=0;
        head=head->next;
        while(head!=nullptr){
            sum=sum+head->val;
            if(head->val==0){
                head->val=sum;
                sum=0;
                temp2->next=head;
                temp2=temp2->next;
            }
            head=head->next;
        }
        return temp->next;
    }
};