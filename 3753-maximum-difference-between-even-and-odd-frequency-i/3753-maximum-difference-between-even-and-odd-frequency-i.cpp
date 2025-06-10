class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(char i:s)mp[i]++;
        int n=s.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp[s[i]]%2==1 && mp[s[j]]%2==0)
                mx=max(mx,(mp[s[i]]-mp[s[j]]));
                if(mp[s[i]]%2==0 && mp[s[j]]%2==1)
                mx=max(mx,(mp[s[j]]-mp[s[i]]));
            }
        }return mx;
    }
};