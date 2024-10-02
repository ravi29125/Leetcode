class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums=arr;int n=arr.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int j=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end())mp[nums[i]]=++j;
        }
        nums.clear();
        for(int i:arr){
            nums.push_back(mp[i]);
        }return nums;
    }
};