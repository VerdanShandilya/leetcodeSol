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
    bool isPalindrome(ListNode* head) {
        stack<int>s;
        vector<int> v;
        ListNode* temp=head;
        while(temp!=nullptr){
            s.push(temp->val);
            temp=temp->next;
        }
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        bool ans=true;
        int i=0;
        while(head!=nullptr){
            if(v[i]!=head->val){
                ans=false;
                break;
            }
            head=head->next;
            i++;
        }
        return ans;
    }
};