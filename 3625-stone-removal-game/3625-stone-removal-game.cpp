class Solution {
public:
    bool canAliceWin(int n) {
        int cnt=10;
        int b=0;
        while(n>0 && cnt>0){
            if(n>=cnt)n-=cnt;
            else break;
            b++;
            cnt--;
            //cout<<b<<" ";
        }return b%2==1 && b!=0;
    }
};