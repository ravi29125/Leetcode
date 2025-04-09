class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i:nums)mp[i]++;
        vector<int> arr;
        for(auto k:mp)arr.push_back(k.first);
        if(arr[0]<k)return -1;
        else if(arr[0]==k)return arr.size()-1;
        return arr.size();
    }
};