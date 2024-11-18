class Solution {
    bool help(int n,vector<int> &nums,vector<vector<int>>q){
        vector<int> arr(1e5+1,0);
        for(int i=0;i<n;i++){
            arr[q[i][0]]+=q[i][2];
            arr[q[i][1]+1]-=q[i][2];
        }
        for(int i=0;i<nums.size();i++){
            if(i>0)arr[i]+=arr[i-1];
            if(arr[i]<nums[i])return false;
        }return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int i=0,j=queries.size();
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(help(mid,nums,queries)){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }return ans;
    }
};