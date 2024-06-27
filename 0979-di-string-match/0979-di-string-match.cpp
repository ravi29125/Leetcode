class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int> arr(n+1);
        int low=0,high=n;
        for(int i=0;i<n;i++){
            s[i]=='I' ? arr[i]=low++ : arr[i]=high--;
        }
        s[n-1]=='I' ? arr[n]=low++ : arr[n]=high--;
        return arr;
    }
};