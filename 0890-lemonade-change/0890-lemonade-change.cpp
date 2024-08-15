class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a,b,c;
        a=b=c=0;
        for(int i:bills){
            if(i==5)a++;
            else if(i==10){
                if(a==0)return false;
                else a--,b++;
            }else{
                if(b>0 && a>0){
                    c++;
                    b--;
                    a--;
                }else if(a>2){
                    a-=3;
                    c++;
                }else return false;
            }
        }return true;
    }
};