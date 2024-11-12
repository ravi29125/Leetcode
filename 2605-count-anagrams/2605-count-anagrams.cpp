class Solution {
    int mod=1e9+7;
    int help(int b,int n){
        long res=1;
        long a=b;
        while(n>0){
            if(n%2)res=(res*a)%mod;
            a=(a*a)%mod;
            n/=2;
        }return res;
    }
public:
    int countAnagrams(string s) {
        long ans=1;
        int mx=0;
        stringstream ss(s);
        string w;
        vector<string> arr;
        while(ss>>w){
            arr.push_back(w);
            mx=max(mx,(int)w.size());
        }
        vector<int> fact(mx+1,0);
        fact[0]=1;
        for(int i=1;i<=mx;i++){
            long long f=(fact[i-1]*(long long)i)%mod;
            fact[i]=f;
        }
        for(auto i:arr){
            vector<int> mp(26,0);
            for(char j:i)mp[j-'a']++;
            ans=(ans*fact[i.size()])%mod;
            for(int k=0;k<26;k++){
                if(mp[k]>0)
                ans=(ans*help(fact[mp[k]],mod-2))%mod;
            }
        }
        return ans;
    }
};