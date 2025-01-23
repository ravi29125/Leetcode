class Solution {
    bool isP(int n){
        int cp=n;
        int rev=0;
        while(cp>0){
            rev*=10;
            rev+=(cp%10);
            cp/=10;
        }return n==rev;
    }
    bool isp(int n){
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }return true;
    }
public:
    int primePalindrome(int n) {
        if(n==1)return 2;
        while(true){
            if(isP(n) && isp(n))return n;
            n++;
            if(10000000<n && n<100000000)n = 100000000;
        }return -1;
    }
};