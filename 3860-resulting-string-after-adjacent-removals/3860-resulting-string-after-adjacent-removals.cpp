class Solution {
public:
    string resultingString(string s) {
        string ref="abcdefghijklmnopqrstuvwxyz";
        string f="bcdefghijklmnopqrstuvwxyza";
        string b="zabcdefghijklmnopqrstuvwxy";
        set<pair<char,char>> st;
        for(int i=0;i<26;i++){
            st.insert({ref[i],f[i]});
            st.insert({ref[i],b[i]});
        }
        stack<char> k;
        for(auto p:s){
            if(k.empty()){
                k.push(p);
            }else if(st.count({p,k.top()})){
                k.pop();
            }else{
                k.push(p);
            }
        }
        string ans="";
        while(!k.empty()){
            ans+=k.top();
            k.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};