class Solution {
    map<tuple<int,int>,int>mp;
    int help(string &s,string &t,int n,int m){
        if(m==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(mp.find({n,m})!=mp.end()) return mp[{n,m}];
        if(s[n-1]==t[m-1]){
            return mp[{n,m}]=help(s,t,n-1,m-1)+help(s,t,n-1,m);
        }
        return mp[{n,m}]=help(s,t,n-1,m);
    }
public:
    int numDistinct(string s, string t) {
        return help(s,t,s.size(),t.size());
    }
};