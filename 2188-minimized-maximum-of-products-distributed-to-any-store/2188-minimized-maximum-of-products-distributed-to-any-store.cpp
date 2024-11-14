class Solution {
    bool help(vector<int> &nums,int n,int k){
        for(int i:nums){
            //cout<<k<<" ";
            //cout<<i<<" "<<(i/k)+((i%k==0)?0:1)<<endl;
            n-=((i/k)+((i%k==0)?0:1));
        }return n>=0;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int i=1,j=1e5;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            int val=help(quantities,n,mid);
            if(val){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }return ans;
    }
};