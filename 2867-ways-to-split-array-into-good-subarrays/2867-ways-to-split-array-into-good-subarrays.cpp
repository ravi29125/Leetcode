class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> arr;
        int n=nums.size();
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            if(nums[i]){
                arr.push_back(i);
            }
        }
        long cnt=1;
        n=arr.size();
        if(n==0)return 0;
        for(int i=1;i<n;i++){
            cnt=(cnt*(arr[i]-arr[i-1]))%mod;
        }return cnt;
    }
};