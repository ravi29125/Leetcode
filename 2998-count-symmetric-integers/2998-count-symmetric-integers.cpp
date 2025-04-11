class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            int val=log10(i)+1;
            if(val%2==0){
                int p=val/2;
                int sum=0;
                int cp=i;
                for(int j=0;j<val;j++){
                    if(j<p)sum+=cp%10;
                    else sum-=cp%10;
                    cp/=10;
                }
                if(sum==0)cnt++;
            }
        }return cnt;
    }
};