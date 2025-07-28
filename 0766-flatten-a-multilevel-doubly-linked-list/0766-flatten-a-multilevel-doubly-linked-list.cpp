/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> st;
        if(head)
        st.push(head);
        Node * res=nullptr,* temp=nullptr;
        while(!st.empty()){
            auto t=st.top();st.pop();
            if(t->next){
                st.push(t->next);
            }
            if(t->child){
                st.push(t->child);
            }
            t->next=t->child=t->prev=nullptr;
            if(!res){
                res=t;
                temp=t;
            }else{
                temp->next=t;
                t->prev=temp;
                temp=t;
            }
        }return res;
    }
};