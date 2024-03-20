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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp;
        ListNode* temp2;
        ListNode* ans=list1;
        int c=a;
        while(a!=1){
            list1=list1->next;
            a--;
        }
        temp=list1->next;
        list1->next=list2;
        int x=b-c;
        while(x!=0){
            temp=temp->next;
            x--;
        }
        temp2=temp->next;
        while(list2->next){
            list2=list2->next;
        }
        list2->next=temp2;
        return ans;
    }
};