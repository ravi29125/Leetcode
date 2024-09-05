class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int sum=0;
        for(int i:rolls){
            sum+=i;
        }
        long val=mean*(n+rolls.size());
        val-=sum;
        if(val<1)return {};
        //cout<<val<<" ";
        while(n>0){
            if(val/n >6 || val/n < 1)return {};
            //cout<<val<<" "<<n<<endl;
            ans.push_back(int(val/n));
            val-=int(val/n);
            n--;
        }return ans;
    }
};