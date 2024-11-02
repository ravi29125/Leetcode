class Solution {
public:
    bool isCircularSentence(string s){
        s+=' ';
        vector<char> a1,a2;
        string r="";
        for(char i:s){
            if(isalpha(i)){
                r+=i;
            }else if(r.size()!=0){
                a1.push_back(r[0]);
                a2.push_back(r.back());
                r="";
            }
        }
        int n=a1.size();
        for(int i=0;i<n;i++){
            //cout<<a2[i]<<" "<<a1[(i+1)%n]<<endl;
            if(a2[i]!=a1[(i+1)%n])return false;
        }return true;
    }
};