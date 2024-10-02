class Solution {
public:
    int findMin(vector<int>& nums) {
        int mx=nums[0];
        int n=nums.size();
        mx=min(nums[n-1],mx);
        if(n==2)return mx;
        int i=0,j=n-1;
        while(i<j){
            int mid=i+(j-i)/2;
            //cout<<mid<<" ";
            if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1])return min(mx,nums[mid]);
            else if(nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1] && nums[mid-1]<nums[0]) j=mid-1;
            else i=mid+1;
        }return min(mx,nums[i]);
    }
};