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
        if(!head || !head->next)return head;
        ListNode* odd,*even,*o,*e;
        o=e=nullptr;
        odd=even=nullptr;
        ListNode *curr=head;
        int cnt=0;
        while(curr!=nullptr){
            if(cnt%2==1){
                if(!odd){
                    o=odd=curr;
                }else{
                    odd->next=curr;
                    odd=curr;
                }
            }else{
                if(!even){
                    e=even=curr;
                }else{
                    even->next=curr;
                    even=curr;
                }
            }
            curr=curr->next;
            cnt++;
        }
        even->next=o;
        odd->next=nullptr;
        return e;
        return head;
    }
};