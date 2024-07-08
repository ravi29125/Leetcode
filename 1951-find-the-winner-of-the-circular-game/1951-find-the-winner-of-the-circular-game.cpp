class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
            //cout<<q.front();
            //q.pop();
        }
        int cnt=0;
        while(q.size()>1){
            cnt++;
            int val=q.front();q.pop();
            if(cnt==k){
                cnt=0;
            }else{
                q.push(val);
            }
        }
        return q.front();
    }
};