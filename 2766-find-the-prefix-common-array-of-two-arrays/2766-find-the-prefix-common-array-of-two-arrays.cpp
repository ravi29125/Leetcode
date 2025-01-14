class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int n=A.size(),cnt=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(mp[A[i]]==2)cnt++;
            if(A[i] != B[i] && mp[B[i]]==2)cnt++;
            ans.push_back(cnt);
        }return ans;
    }
};