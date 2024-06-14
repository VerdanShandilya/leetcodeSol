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
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode * prev = NULL;
        ListNode *curr = head;
        ListNode *nextnode = NULL;
        while(curr!=NULL){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        while(temp1!=nullptr && temp1->next!=nullptr){
            temp=temp->next;
            temp1=temp1->next->next;
        }
        ListNode* reve=reverse(temp);
        while(reve!=nullptr){
            if(head->val!=reve->val){
                return false;
            }
            head=head->next;
            reve=reve->next;
        }
        return true;
    }
};