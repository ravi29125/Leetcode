class Solution {
    int ans=INT_MAX;
    void help(vector<int>& nums,int n,vector<int> &arr,int k){
        if(n==0){
            int mx=arr[0];
            for(int i:arr)mx=max(mx,i);
            ans=min(ans,mx);
            return;
        }
        n--;
        for(int j=0;j<k;j++){
            if(arr[j]+nums[n]>ans)continue;
            arr[j]+=nums[n];
            help(nums,n,arr,k);
            arr[j]-=nums[n];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> arr(k,0);
        help(cookies,cookies.size(),arr,k);
        return ans;
    }
};