class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        bool flag=true;
        int j=0;
        int n=str1.size(),m=str2.size();
        for(int i=0;i<n&&j<m;i++){
            //cout<<((str1[i]-'a')+1)%26<<" "<<(str2[j]-'a')%25<<endl;
            if(str1[i]==str2[j] || ((str1[i]-'a'+1)+1)%26 == (str2[j]-'a'+1)%26){
                j++;
            }
        }
        //cout<<'z'-'a'<<endl;
        return j==m;
    }
};