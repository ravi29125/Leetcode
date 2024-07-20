class Solution {
public:
    string losingPlayer(int x, int y) {
        int cnt=0,i=2;
        while(x>0 && y>3){
            cnt++,y-=4,x-=1;
        }return cnt%2==1 ? "Alice":"Bob";
    }
};