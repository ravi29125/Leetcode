class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(nums[i]&1)arr.push_back(i);
        }
        int m=arr.size();
        if(m<k)return 0;
        int cnt=0;
        for(int i=0;i<=m-k;i++){
            int l=(i==0)?arr[i]+1:arr[i]-arr[i-1];
            int r=(i+k==m)?n-arr[i+k-1]:arr[i+k]-arr[i+k-1];
            cnt+=l*r;
        }
        //cnt+=max(0,n-nums[m-1]);
        return cnt;
    }
};