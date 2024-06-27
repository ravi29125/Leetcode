class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        int cn=0,mx=0;
        vector<int> suff(n);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>-1;i--){
            suff[i]=min(nums[i],suff[i+1]);
        }
        //for(int i:suff)cout<<i<<" ";cout<<endl;
        mx=nums[0];
        int ans=0;
        for(int i=1;i<n-1;i++){
            //cout<<suff[i+1]<<" "<<nums[i]<<" "<<mx<<endl;
            if(suff[i+1]>nums[i] && nums[i]>mx){
                ans+=2;
            }else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                ans+=1;
            }mx=max(mx,nums[i]);
        }return ans;
    }
};