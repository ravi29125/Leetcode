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
    int pairSum(ListNode* head) {
        ListNode* t=head;
        stack<int> st;
        while(t){
            st.push(t->val);
            t=t->next;
        }
        t=head;
        int mx=0;
        while(t){
            mx=max(mx,st.top()+t->val);st.pop();
            t=t->next;
        }return mx;
    }
};