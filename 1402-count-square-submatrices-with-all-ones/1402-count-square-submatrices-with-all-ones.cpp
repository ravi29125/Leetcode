class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=matrix[i][j];
                if(i>0){
                    arr[i][j]+=arr[i-1][j];
                }
                if(j>0){
                    arr[i][j]+=arr[i][j-1];
                }
                if(i>0 && j>0){
                    arr[i][j]-=arr[i-1][j-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    ans++;
                    int p=i+1,q=j+1;
                    int cnt=2;
                    while(p<n && q<m && (arr[p][q]-((i==0)?0:arr[i-1][q])-((j==0)?0:arr[p][j-1])+((i>0 && j>0)?arr[i-1][j-1]:0))==cnt*cnt){
                        cnt++;
                        ans++;
                        p++;
                        q++;
                    }
                }
            }
        }
        return ans;
    }
};