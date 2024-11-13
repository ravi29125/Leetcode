class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        //for(int i:nums)cout<<i<<" ";cout<<endl;
        for(int k=0;k<n-1;k++){
            int i=k+1,j=n-1;
            int st=-1;
            while(i<=j){
                int mid=(i+j)/2;
                if(nums[mid]+nums[k]<l){
                    i=mid+1;
                }else{
                    st=mid;
                    j=mid-1;
                }
            }
            i=k+1,j=n-1;
            int en=-1;
            while(i<=j){
                int mid=(i+j)/2;
                if(nums[mid]+nums[k]>u){
                    j=mid-1;
                }else{
                    en=mid;
                    i=mid+1;
                }
            }
            if(st!=-1 && en!=-1)ans+=(en-st+1);
            //cout<<st<<" "<<en<<endl;
        }return ans;
    }
};