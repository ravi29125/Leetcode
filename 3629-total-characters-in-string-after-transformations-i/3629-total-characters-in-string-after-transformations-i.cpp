class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> arr(26,0);
        int mod=1e9+7;
        for(char i:s)arr[i-'a']++;
        for(int i=0;i<t;i++){
            int val=arr[25];
            arr[25]=0;
            for(int j=24;j>-1;j--){
                arr[j+1]=(arr[j+1]+arr[j])%mod;
                arr[j]=0;
            }
            arr[0]=(arr[0]+val)%mod;
            arr[1]=(arr[1]+val)%mod;
        }
        int res=0;
        for(int i:arr){
            res=(res+i)%mod;
        }return res;
    }
};