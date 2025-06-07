class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> ans;
        for(int i=0;i+k<=n;i++){
            vector<int> arr;
            for(int j=0;j+k<=m;j++){
                priority_queue<int> pq;
                for(int l=0;l<k;l++){
                    for(int p=0;p<k;p++){
                        pq.push(grid[i+l][j+p]);
                    }
                }
                int tp=pq.top();pq.pop();
                int a=INT_MAX;
                while(!pq.empty()){
                    if(tp!=pq.top())
                    a=min(a,abs(tp-pq.top()));
                    tp=pq.top();
                    pq.pop();
                }
                a=((a==INT_MAX)?0:a);
                arr.push_back(a);
            }
            ans.push_back(arr);
        }return ans;
    }
};