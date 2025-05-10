class Solution {
    bool is(string s){
        int c1=0,c2=0;
        for(char i:s){
            if(i=='(')c1++;
            else c2++;
            if(c2>c1) return false;
        }return c1==c2;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();int m=grid[0].size();
        if(grid[0][0]==')' || grid[n-1][m-1]=='(') return false;
        //vector<vector<vector<pair<int,int>>>> dp(n,);
        vector<set<pair<int,int>>> dp(m);
        for(int i=0;i<n;i++){
            vector<set<pair<int,int>>> t(m); 
            if(i==0)t[0].insert({1,0});
            for(int j=0;j<m;j++){
                if(i-1>=0){
                    for(auto p:dp[j]){
                        bool b=grid[i][j]=='(';
                        if(b)
                        t[j].insert({p.first+1,p.second});
                        else if(p.second+1<=p.first)
                        t[j].insert({p.first,p.second+1});
                    }
                }
                if(j-1>=0){
                    for(auto p:t[j-1]){
                        bool b=grid[i][j]=='(';
                        if(b)
                        t[j].insert({p.first+1,p.second});
                        else if(p.second+1<=p.first)
                        t[j].insert({p.first,p.second+1});
                    }
                }
            }
            dp=t;
        }
        for(auto p:dp[m-1])if(p.first==p.second) return true;
        return false;
    }
};