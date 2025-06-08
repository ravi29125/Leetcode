class Solution {
    vector<int> arr;
    void help(int n,int num){
        if(num>n)return ;
        for(int i=(num==0?1:0);i<=9;i++){
            int val=num*10+i;
            if(val<=n){
                arr.push_back(val);
                help(n,val);
            }else break;
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        help(n,0);
        return arr;
    }
};