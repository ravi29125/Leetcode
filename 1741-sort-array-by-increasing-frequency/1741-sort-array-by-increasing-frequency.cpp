class Solution {
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums)mp[i]++;
        vector<pair<int,int>> a;
        for(auto k:mp){
            a.push_back({k.second,k.first});
        }
        int i=0;
        sort(a.begin(),a.end(),cmp);
        int n=a.size();
        for(auto val:a){
            //auto val=a[n];
            int j=val.first;
            while(j--){
                nums[i++]=val.second;
            }
        }return nums;
    }
};