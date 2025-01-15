class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int val=__builtin_popcount(num2);
        int ans=0;
        vector<int> arr(32,0);
        for(int i=0;i<32;i++){
            arr[i]=((num1>>i)&1);
        }
        for(int i=31;i>-1;i--){
            if(arr[i]==1)val--;
            if(val<0 && arr[i]==1)arr[i]=0;
        }
        int i=0;
        while(i<32 && val>0){
            if(arr[i]==1)i++;
            else arr[i++]=1,val--;
        }
        for(int i=31;i>-1;i--){
            if(arr[i]==1){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};