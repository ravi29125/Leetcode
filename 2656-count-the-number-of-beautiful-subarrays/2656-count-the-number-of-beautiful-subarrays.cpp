class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long cnt=0;
        int num=0;
        mp[0]++;
        for(int i:nums){
            num^=i;
            cnt+=mp[num];
            mp[num]++;
        }return cnt;
    }
};