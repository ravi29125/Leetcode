class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<long long> a1(n,0),a2(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
                a1[i]+=grid[i][j];
                a2[j]+=grid[i][j];
            }
        } 
        if(sum%2==1)return false;
        sum/=2;
        //cout<<sum<<" "<<endl;for(auto k:a1)cout<<k<<" ";cout<<endl;for(auto k:a2)cout<<k<<" ";cout<<endl;
        long long v1=0;
        for(int i:a1){
            v1+=i;
            if(v1==sum)return true;
        }
        v1=0;
        for(int i:a2){
            v1+=i;
            if(v1==sum)return true;
        }
        return false;
    }
};