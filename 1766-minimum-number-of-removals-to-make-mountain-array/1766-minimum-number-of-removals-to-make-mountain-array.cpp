class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,0);
        int ans=n;
        for(int i=0;i<n;i++){
            int j=i-1;
            int val=-1;
            while(j>-1){
                if(arr[j]>val && nums[i]>nums[j])val=arr[j];
                j--;
            }
            if(val==-1){
                arr[i]=1;
            }else{
                arr[i]=val+1;
            }
        }
        vector<int> rev(n,0);
        for(int i=n-1;i>-1;i--){
            int j=i+1;
            int val=-1;
            while(j<n){
                if(rev[j]>val && nums[i]>nums[j])val=rev[j];
                j++;
            }
            if(val==-1){
                rev[i]=1;
            }else{
                rev[i]=val+1;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==1 || rev[i]==1)continue;
            ans=min(ans,n-(arr[i]+rev[i]-1));
            //cout<<arr[i]<<" "<<rev[i]<<endl;
        }
        //for(int i:arr)cout<<i<<" ";cout<<endl;
        //for(int i:rev)cout<<i<<" ";cout<<endl;
        return ans;
    }
};