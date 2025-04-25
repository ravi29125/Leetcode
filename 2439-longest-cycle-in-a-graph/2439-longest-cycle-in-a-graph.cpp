class Solution {
public:
    int longestCycle(vector<int>& e) {
        int n=e.size();
        int ans=-1;
        vector<vector<int>> arr(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int curr=e[i];
            int cnt=0;
            while(curr!=-1 && arr[curr][0]==-1){
                arr[curr][0]=i+1;
                cnt++;
                arr[curr][1]=cnt;
                curr=e[curr];
            }
            if(curr!=-1 && arr[curr][0]==i+1){
                ans=max(ans,cnt-arr[curr][1]+1);
            }
        }
        return ans;
    }
};