class trie{
    public:
    char ch;
    int cnt;
    unordered_map<char,trie*> mp;
    trie(char ch){
        this->ch=ch;
        cnt=0;
    }
};

class Solution {
    trie *st;
    void add(string s){
        trie *t=st;
        for(char i:s){
            if(t->mp.find(i)==t->mp.end()){
                t->mp[i]=new trie(i);
            }
            t=t->mp[i];
            t->cnt++;
            //cout<<t->ch<<" "<<t->cnt<<endl;
        }
    }
    int cmp(string s){
        trie *t=st;
        int val=0;
        for(char i:s){
            if(t->mp.find(i)==t->mp.end()){
                break;               
            }else{
                t=t->mp[i];
                val+=t->cnt;
            }
        }return val;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        st=new trie('\0');
        for(string i:words){
            add(i);
        }
        for(string i:words){
            int val=cmp(i);
            ans.push_back(val);
        }return ans;
    }
};