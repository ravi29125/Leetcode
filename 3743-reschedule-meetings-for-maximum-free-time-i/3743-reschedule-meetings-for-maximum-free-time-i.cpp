class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        //vector<int> arr(eventTime+1,0);
        int n=startTime.size();
        vector<int> ar;
        int st=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            int val=startTime[i]-st;
            if(val>0){
                ar.push_back(val);
            }
            st=endTime[i];
            ar.push_back(-(i+1));
        }
        if(eventTime-st >0){
            ar.push_back(eventTime-st);
        }
        //for(int i:ar)cout<<i<<" ";
        n=ar.size();
        int j=0;
        cnt=0;
        int ans=0;
        int val=0;
        for(int i=0;i<n;i++){
            if(ar[i]<0){
                cnt++;
            }else{
                val+=ar[i];
            }
            while(cnt>k){
                if(ar[j]<0)cnt--;
                else val-=ar[j];
                j++;
                //ans=max(ans,val);
            }
            ans=max(ans,val);
        }
        return ans;
    }
};