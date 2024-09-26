class Solution {
public:
    int numberOfSubstrings(string s) {
        int j=0;
        int a=0,b=0,c=0;
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;
            if(a>0 && b>0 && c>0){
                cnt+=(n-i);
                cout<<i<<" "<<j<<endl;
                cout<<cnt<<endl;
                if(s[j]=='a')a--;
                else if(s[j]=='b')b--;
                else c--;
                j++;
                while(a>0 && b>0 && c>0 && j<i){
                    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
                    //cnt+=n-i;
                    cnt+=(n-i);
                    if(s[j]=='a')a--;
                    else if(s[j]=='b')b--;
                    else c--;
                    j++;
                }
                cout<<endl;
            }
        }return cnt;
    }
};