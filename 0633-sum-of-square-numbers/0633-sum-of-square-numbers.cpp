class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            long val=c-i*i;
            long sq=sqrt(val);
            if(val==sq*sq) return true;
        }return false;
    }
};