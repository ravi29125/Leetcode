class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int val=0;
        for(int i:nums){
            val=((i%k)+k)%k;
            mp[val]++;
        }
        if(mp[0]%2==1)return false;
        for(int i=1;i<k;i++){
            if(mp[i]!=mp[k-i])return false;
        }return true;
    }
};