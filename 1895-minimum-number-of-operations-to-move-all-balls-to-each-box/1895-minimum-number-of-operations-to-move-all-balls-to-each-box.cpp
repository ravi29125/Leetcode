class Solution {
public:
    vector<int> minOperations(string box) {
        int n=box.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(i!=j && box[j]=='1')
                ans[i]+=abs(j-i);
            }
        }return ans;
    }
};