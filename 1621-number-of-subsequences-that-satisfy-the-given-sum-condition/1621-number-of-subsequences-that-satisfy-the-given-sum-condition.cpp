class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size(),mod=1e9+7;
        sort(nums.begin(),nums.end());
        vector<long> pow(n,1);
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }
        int l=0,r=n-1;
        long res=0;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                res=(res+pow[r-l])%mod;
                l++;
            }else{
                r--;
            }
        }return (int)res;
    }
};