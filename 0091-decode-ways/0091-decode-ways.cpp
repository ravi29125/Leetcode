class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0 || s[0]=='0')return 0;
        if(n==1) return 1;
        vector<int> arr(n+1,0);
        arr[0]=1;
        arr[1]=1;
        for(int i=1;i<n;i++){
            if(s[i]!='0')arr[i+1]+=arr[i];
            if(s[i-1]=='1'||(s[i-1]=='2' &&s[i]<'7'))arr[i+1]+=arr[i-1];
        }return arr[n];
    }
};