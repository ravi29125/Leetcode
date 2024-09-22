class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1')return false;
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(s[i]=='0')arr.push_back(i);
        }
        int m=arr.size();
        vector<bool> dp(m,false);
        dp[0]=true;
        int j=0;
        for(int i=0;i<m;i++){
            if(dp[i]){
                int mi=arr[i]+minJump,mx=arr[i]+maxJump;
                while (j<m && arr[j]<mi)j++;
                while(j<m && arr[j]<=min(n-1,mx))dp[j++]=true;
            }
        }
        for(auto k:dp)cout<<k<<" ";
        return dp[m-1];
    }
};