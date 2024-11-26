class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> arr(n,0);
        for(auto k:edges)arr[k[1]]--;
        int j=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[j])j=i;
        }
        int cnt=0;
        for(int i:arr){
            if(i==arr[j])cnt++;
            if(cnt>1)return -1;
        }return j;
    }
};