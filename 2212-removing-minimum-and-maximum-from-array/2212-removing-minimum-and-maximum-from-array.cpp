class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mi=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        unordered_set<int> s;
        int j=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            while(s.count(mi) || s.count(mx))s.erase(nums[j++]);
            ans=max(ans,(int)s.size());
        }
        return nums.size()-ans;
    }
};