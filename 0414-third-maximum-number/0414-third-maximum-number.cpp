class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a,b,c;
        a=b=c=LONG_MIN;
        for(int i:nums){
            if(i==a || i==b || i==c)continue;
            if(i>a){
                c=b;
                b=a;
                a=i;
            }else if(i>b){
                c=b;
                b=i;
            }else if(i>c){
                c=i;
            }
        }
        if(b==LONG_MIN||c==LONG_MIN)return a;
        return c;
    }
};