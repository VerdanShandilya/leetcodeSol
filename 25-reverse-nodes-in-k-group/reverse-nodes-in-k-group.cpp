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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* dummy1=dummy;
        ListNode* temp=head;
        stack<ListNode*> s;
        int count=0;
        while(temp!=nullptr){
            s.push(temp);
            count++;
            temp=temp->next;
            if(count==k){
                while(!s.empty()){
                    auto val=s.top();
                    dummy1->next=val;
                    s.pop();
                    dummy1=dummy1->next;
                }
                dummy1->next=temp;
                count=0;
            }
        }
        return dummy->next;
    }
};