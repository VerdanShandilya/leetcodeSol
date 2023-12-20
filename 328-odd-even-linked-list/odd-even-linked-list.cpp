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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        vector<int> left;
        vector<int> right;
        ListNode* temp=head;
        int c=1;
        while(temp){
            if(c%2==0){
                right.push_back(temp->val);
            }
            else{
                left.push_back(temp->val);
            }
            temp=temp->next;
            c++;
        }
        int i=0;
        temp=head;
        while(i<=left.size()-1){
            temp->val=left[i];
            i++;
            temp=temp->next;
        }i=0;
        while(temp!=nullptr){
            temp->val=right[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};