class Solution {
    bool help(vector<int>& nums,int k){
        long long x=0,o=0;
        k--;
        int j=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
            o+=nums[i];
            if(i>k){
                x^=nums[j];
                o-=nums[j++];
            }
            if(i>=k && x==o) return true;
        }return false;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=1,j=nums.size();
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(help(nums,mid)){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
            //cout<<endl;
        }return ans;
    }
};