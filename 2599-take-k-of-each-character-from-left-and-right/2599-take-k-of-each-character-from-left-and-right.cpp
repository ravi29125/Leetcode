class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> arr(3,0),cnt(3,0);
        int n=s.size();
        //int j=0;
        int ans=0;
        for(char i:s)cnt[i-'a']++;
        for(int i=0;i<3;i++)if(cnt[i]<k)return -1;
        cnt[0]-=k;
        cnt[1]-=k;
        cnt[2]-=k;
        int j=0;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            while(j<=i && arr[0]>cnt[0] or arr[1]>cnt[1] or arr[2]>cnt[2]){
                arr[s[j]-'a']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return n-ans;
    }
};