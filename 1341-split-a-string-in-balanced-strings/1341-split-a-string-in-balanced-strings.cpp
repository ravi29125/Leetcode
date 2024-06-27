class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int cnt=0;
        int n=s.size();
        if(s[0]=='L')cnt++;
        else cnt--;
        for(int i=1;i<n;i++){
            if(s[i]=='L')cnt++;
            else cnt--;
           //cout<<cnt<<" ";
            if(cnt==0)ans++;
        }return ans;
    }
};