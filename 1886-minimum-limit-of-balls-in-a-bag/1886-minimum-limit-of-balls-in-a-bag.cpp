class Solution {
    bool help(vector<int> &nums,int k,int op){
        int n=nums.size();
        int cnt=0;
        for(int i:nums){
            cnt+=(i/k);
            if(i%k!=0)cnt++;
        }
        //cout<<k<<endl;
        //cout<<cnt<<" "<<n+k<<endl;
        return cnt<=n+op;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int i=1;
        int j=(*max_element(nums.begin(),nums.end()));
        int ans=j;
        j--;
        while(i<=j){
            int mid=(i+j)/2;
            if(help(nums,mid,maxOperations)){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};