class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(auto k:prerequisites){
            arr[k[0]][k[1]]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(arr[j][k]==0 && arr[j][i]==1 && arr[i][k]==1){
                        arr[j][k]=1;
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto k:queries){
            if(arr[k[0]][k[1]]==1)ans.push_back(true);
            else ans.push_back(false);
        }return ans;
    }
};