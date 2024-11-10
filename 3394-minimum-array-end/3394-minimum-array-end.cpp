class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x,mask;
        vector<int> bn(64);
        long long val=n-1;
        for(int i=0;i<64;i++){
            bn[i]=(val&1);
            val>>=1;
        }
        int j=0;
        for(int i=0;i<64;i++){
            mask=(1LL<<i);
            if((mask&ans)==0){
                if(bn[j]==1)ans=mask|ans;
                j++;
            }
        }return ans;
    }
};