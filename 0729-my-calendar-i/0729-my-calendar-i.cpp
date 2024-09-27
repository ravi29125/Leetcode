class Node{
    public:
    int l;
    int r;
    Node *right,*left;
    Node(int l,int r){
        this->l=l;
        this->r=r;
        right=left=nullptr;
    }
};
class MyCalendar {
    Node *st;
public:
    MyCalendar() {
        st=nullptr;
    }
    
    bool help(int l,int r,Node * root){
        if(root->l>l && root->l>=r){
            if(root->left==nullptr){
                root->left=new Node(l,r);
                return true;
            }else{
                return help(l,r,root->left);
            }
        }
        if(root->r<=l && root->r<r){
            if(root->right==nullptr){
                root->right=new Node(l,r);
                return true;
            }else{
                return help(l,r,root->right);
            }
        }return false;
    }

    bool book(int start, int end) {
        if(st==nullptr){
            st=new Node(start,end);
            return true;
        }else{
            return help(start,end,st);
        }return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */