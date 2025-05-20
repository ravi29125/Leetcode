class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> arr(n+1,0);
        for(auto k:queries){
            arr[k[0]]++;
            arr[k[1]+1]--;
        }
        for(int i=1;i<=n;i++){
            arr[i]+=arr[i-1];
            //cout<<arr[i-1]<<" ";
        }
        for(int i=0;i<n;i++){
            nums[i]-=arr[i];
            if(nums[i]<0)nums[i]=0;
            //cout<<nums[i]<<" ";
            if(nums[i]!=0)return false;
        }return true;
    }
};