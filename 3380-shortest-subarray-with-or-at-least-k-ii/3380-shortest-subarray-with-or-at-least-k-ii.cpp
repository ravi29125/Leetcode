class Solution {
    vector<vector<int>> pre;
    int help(vector<int>& arr,int i,int n){
        int our=0;
        for(int j=0;j<32;j++){
            if((pre[n+1][j]-pre[i][j]) > 0)our+=pow(2,j);
        }
        return our;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int p) {
        int our=0;
        for(int i:nums)our|=i;
        if(our<p)return -1;
        int n=nums.size(),mi=n;
        pre=vector<vector<int>>(n+1,vector<int>(32,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++)
            pre[i+1][j]=pre[i][j]+((nums[i]&(1<<j))>0);
        }
        /*
            for(auto o:pre){
                for(auto h:o)cout<<h<<" ";
                cout<<endl;
            }
        */
        for(int i=0;i<n;i++){
            int h,k;
            h=i,k=n-1;
            our=-1;
            while(h<=k){
                int mid=(h+k)/2;
                int val=help(nums,i,mid);
                if(val>=p){
                    our=mid;
                    k=mid-1;
                }else{
                    h=mid+1;
                }
            }
            if(our!=-1)mi=min(mi,our-i+1);
        }
        return mi;
    }
};