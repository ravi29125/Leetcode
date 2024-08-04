class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long sum=0;
        vector<long> arr;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum=(sum+nums[j])%mod;
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        sum=0;
        for(int i=left-1;i<right;i++){
            sum=(arr[i]+sum)%mod;
        }return sum;
    }
};