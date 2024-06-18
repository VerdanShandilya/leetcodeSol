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
        ListNode* ans;
        ListNode* ans1;
        ListNode* temp;
        temp=l1;
        int cnt=0;
        int cnt1=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        temp=l2;
        while(temp){
            temp=temp->next;
            cnt1++;
        }
        if(cnt>=cnt1){
            ans=l1;
            ans1=l2;
        }
        else{
            ans=l2;
            ans1=l1;
        }
        while(ans!=nullptr || ans1!=nullptr){
            sum=0;
            if(ans!=nullptr){
                sum+=ans->val;
            }
            if(ans1!=nullptr){
                sum+=ans1->val;
                ans1=ans1->next;
            }
            sum+=extra;
            extra=sum/10;
            ans->val=sum%10;
            if(ans->next==nullptr){
                temp=ans;
            }
            ans=ans->next;
        }
        if(extra!=0){
            ListNode* dummy2=new ListNode(extra);
            temp->next=dummy2;
        }
        if(cnt>=cnt1){
            return l1;
        }
        return l2;
    }
};