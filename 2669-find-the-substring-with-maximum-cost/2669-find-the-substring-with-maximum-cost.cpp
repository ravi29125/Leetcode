class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n=s.size();
        vector<int> cnt(26,0);
        for(int i=0;i<26;i++){
            cnt[i]=i+1;
        }
        int m=chars.size();
        for(int i=0;i<m;i++){
            cnt[chars[i]-'a']=vals[i];
        }
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            arr[i]=cnt[s[i]-'a'];   
        }
        int sum=0;
        int ans=0;
        for(int i:arr){
            sum+=i;
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
};