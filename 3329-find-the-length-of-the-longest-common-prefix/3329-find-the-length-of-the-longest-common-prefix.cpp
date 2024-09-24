class trie{
    public:
    char a;
    unordered_map<char,trie*> mp;
    trie(char ch){
        this->a=ch;
    }
};
class Solution {
    trie *st;
    void add(int num){
        string s=to_string(num);
        trie* t=st;
        for(char i:s){
            if(t->mp.find(i)==t->mp.end())
            t->mp[i]=new trie(i);
            t=t->mp[i];
        }
    }
    int help(int num){
        string s=to_string(num);
        trie* t=st;
        int cnt=0;
        for(char i:s){
            if(t->mp.find(i)==t->mp.end())break;
            cnt++;
            cout<<i<<" "<<cnt<<" - ";
            t=t->mp[i];
        }
        cout<<endl;
        return cnt;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        st=new trie('\0');
        for(int i:arr1) add(i);
        int mx=0;
        for(int i:arr2){
            mx=max(mx,help(i));
        }
        return mx;
    }
};