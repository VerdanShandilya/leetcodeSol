/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* temp=headA;
        // ListNode* temp1=headB;
        // while(temp!=temp1){
        //     if(temp==nullptr){
        //         temp=headB;
        //     }
        //     else{
        //         temp=temp->next;
        //     }
        //     if(temp1==nullptr){
        //         temp1=headA;
        //     }
        //     else{
        //         temp1=temp1->next;
        //     }
        // }
        // return temp1;
        unordered_map<ListNode*,int> m;
        ListNode* temp=headA;
        ListNode* temp1=headB;
        while(temp!=nullptr){
            m[temp]++;
            temp=temp->next;
        }
        while(temp1!=nullptr){
            if(m[temp1]==1){
                return temp1;
            }
            temp1=temp1->next;
        }
        return nullptr;
    }
};