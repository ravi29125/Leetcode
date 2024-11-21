class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        int n=s.size();
        vector<int> arr(n,0);
        for(int i=1;i<n;i++){
            int pre=arr[i-1];
            while(pre>0 && s[i]!=s[pre]){
                pre=arr[pre-1];
            }
            arr[i]=pre+(s[i]==s[pre]);
        }
        //for(int i:arr)cout<<i<<" ";
        int ans=arr[n-1];
        while(ans>0 && (n-ans)%k!=0){
            ans=arr[ans-1];
        }
        return ans==0?(n+k-1)/k:(n-ans)/k;
    }
};