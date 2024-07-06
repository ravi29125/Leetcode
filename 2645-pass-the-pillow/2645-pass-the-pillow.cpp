class Solution {
public:
    int passThePillow(int n, int time) {
        time%=2*(n-1);
        if(time>=n)return 2*(n-1)-time+1;
        return time+1;
    }
};