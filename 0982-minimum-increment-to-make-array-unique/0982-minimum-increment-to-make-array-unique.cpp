class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        set<int> s;
        for(int i:nums){
            mp[i]++;
            s.insert(i);
        }
        int ans=0;
        for(int i:s){
            if(mp[i]>1){
                ans+=mp[i]-1;
                mp[i+1]+=mp[i]-1;
                s.insert(i+1);
            }
        }return ans;
    }
};