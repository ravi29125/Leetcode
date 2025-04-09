class Solution {
    bool help(vector<int>& nums,int val,vector<bool>& arr,int st,int curr,int k,int n){
        if(k==0) return true;
        if(curr==val) return help(nums,val,arr,0,0,k-1,n);
        for(int i=st;i<n;i++){
            if(!arr[i] && curr+nums[i]<=val){
                arr[i]=true;
                if(help(nums,val,arr,i+1,curr+nums[i],k,n)) return true;
                arr[i]=false;
            }
        }return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int val=0;
        for(int i:nums)val+=i;
        if(val%k!=0)return false;
        val/=k;
        vector<bool> arr(nums.size(),false);
        return help(nums,val,arr,0,0,k,nums.size());
    }
};