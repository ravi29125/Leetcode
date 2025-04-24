class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        unordered_set<int> s1,s2;
        for(int i:nums)s1.insert(i);
        for(int i=0;i<n;i++){
            s2.clear();
            for(int j=i;j<n;j++){
                s2.insert(nums[j]);
                if(s2.size()==s1.size()){
                    ans++;
                }
            }
        }
        return ans;
    }
};