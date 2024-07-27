class Solution {
public:
    long long minimumCost(string s,string t,vector<char>&o,vector<char>&c,vector<int>&cost) {
        vector<vector<long long>> grid(26,vector<long long>(26,LLONG_MAX));
        int n=o.size();
        for(int i=0;i<n;i++){
            grid[o[i]-'a'][c[i]-'a']=min(grid[o[i]-'a'][c[i]-'a'],(long long)cost[i]);
        }
        n=26;
        for(int i=0;i<n;i++)grid[i][i]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(grid[j][i]!=LLONG_MAX && grid[i][k]!=LLONG_MAX)
                    grid[j][k]=min(grid[j][i]+grid[i][k],grid[j][k]);
                }
            }
        }
        n=s.size();
        long long cos=0;
        for(int i=0;i<n;i++){
            if(grid[s[i]-'a'][t[i]-'a']==LLONG_MAX)return -1;
            cos+=grid[s[i]-'a'][t[i]-'a'];
        }return cos;
    }
};