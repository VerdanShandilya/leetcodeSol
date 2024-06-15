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
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
        stack<ListNode*> s;
        while(temp!=nullptr){
            while(!s.empty() && s.top()->val<temp->val){
                s.pop();
            }
            s.push(temp);
            temp=temp->next;
        }
        ListNode* nxt=nullptr;
        while(!s.empty()){
            temp=s.top();
            s.pop();
            temp->next=nxt;
            nxt=temp;
        }
        return temp;
    }
};