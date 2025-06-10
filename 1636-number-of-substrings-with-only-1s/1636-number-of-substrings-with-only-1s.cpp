class Solution {
public:
    int numSub(string s) {
        int cnt=0,mod=1e9+7;
        long ans=0;
        s+='0';
        for(auto k:s){
            if(k=='1'){
                cnt++;
            }else{
                long long val=cnt;
                cnt=0;
                val=(val*(val+1))/2;
                ans=(ans+val)%mod;
            }
        }
        return ans;
    }
};