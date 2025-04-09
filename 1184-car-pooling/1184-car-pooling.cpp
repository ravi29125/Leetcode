class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<long> arr(1002,0);
        for(auto k:trips){
            arr[k[1]]+=k[0];
            arr[k[2]]-=k[0];
        }
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        for(int i:arr)if(i>capacity) return false;
        return true;
    }
};