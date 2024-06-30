class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int cnt=1,odd=0;
        if(nums[0]&1)odd++;
        for(int i=1;i<n;i++){
            if(nums[i]&1)odd++;
            if(nums[i-1]%2 != nums[i]%2)cnt++;
        }return max({odd,n-odd,cnt});
    }
};