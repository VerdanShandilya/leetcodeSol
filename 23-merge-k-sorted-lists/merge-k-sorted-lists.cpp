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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int>> q;
        for(int i=0;i<lists.size();i++){
            auto temp=lists[i];
            while(temp){
                q.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        while(!q.empty()){
            ListNode* temp=new ListNode(q.top());
            q.pop();
            ans->next=temp;
            ans=ans->next;
        }
        return temp->next;
    }
};