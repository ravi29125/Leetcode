class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=0;
        for(char i:s)if(i=='b')cnt++;
        int c=s.size()-cnt;
        int mx=0,sum=0;
        //cout<<cnt<<" ";
        for(char i:s){
            if(i=='b')cnt--;
            else sum++;
            //cout<<cnt<<" "<<sum<<endl;
            mx=max(cnt+sum,mx);
        }
        sum=0;
        for(char i:s){
            if(i=='a')c--;
            else sum++;
            //cout<<cnt<<" "<<sum<<endl;
            mx=max(cnt+sum,mx);
        }
        return s.size()-mx;
    }
};