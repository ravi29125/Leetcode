class Solution {
    bool help(int mid,vector<int>& nums,int h){
        long cnt=0;
        for(int i:nums){
            cnt+=(i/mid);
            if(i%mid!=0)cnt++;
        }
        return h>=cnt;
    }
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int i=1,j=(*max_element(nums.begin(),nums.end()));
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(help(mid,nums,h)){
                j=mid-1;
                ans=mid;
            }else{
                i=mid+1;
            }
        }return ans;
    }
};