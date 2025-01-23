class Solution {
    unordered_map<int,int> memo;
public:
    int numTrees(int n) {
        if(n<=1)return 1;
        if(memo.find(n)!=memo.end())return memo[n];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);
        }return memo[n]=ans;
    }
};