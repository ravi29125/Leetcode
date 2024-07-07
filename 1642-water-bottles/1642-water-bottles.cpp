class Solution {
public:
    int numWaterBottles(int f, int e) {
        int m=f;
        int cnt=f;
        f=0;
        while(m>=e || f!=0){
            if(f>0){
                m+=f;
                cnt+=f;
                f=0;
            }else{
                f+=m/e;
                m%=e;
            }
        }return cnt;
    }
};