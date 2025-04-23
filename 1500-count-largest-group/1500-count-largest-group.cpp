class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int mx=0;
        for(int i=1;i<=n;i++){
            int sum=0;
            int val=i;
            while(val>0){
                sum+=val%10;
                val/=10;
            }
            mp[sum]++;
            mx=max(mx,mp[sum]);
        }
        int cnt=0;
        for(auto k:mp){
            if(k.second==mx)cnt++;
        }return cnt;
    }
};