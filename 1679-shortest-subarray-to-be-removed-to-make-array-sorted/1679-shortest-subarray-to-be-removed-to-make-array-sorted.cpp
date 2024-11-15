class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 0;
        int l=0,r=n-1;
        while(l+1<n && arr[l]<=arr[l+1])l++;
        while(r-1>-1 && arr[r-1]<=arr[r])r--;
        if(r<l)return 0;
        int ans=r;
        int i,j;
        for(int k=0;k<=l;k++){
            i=r,j=n-1;
            if(arr[j]<arr[k])ans=min(ans,n-k-1);
            while(i<=j){
                int mid=(i+j)/2;
                if(arr[mid]>=arr[k]){
                    //cout<<mid<<" ";
                    ans=min(ans,mid-k-1);
                    j=mid-1;
                }else{
                    i=mid+1;
                }
            }
            //cout<<endl;
        }return ans;
    }
};