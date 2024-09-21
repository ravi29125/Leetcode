class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i+1;
        }sort(ans.begin(),ans.end(),[](int n1 , int n2){return to_string(n1)<to_string(n2);});
        return ans;
    }
};