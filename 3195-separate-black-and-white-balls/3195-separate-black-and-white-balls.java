class Solution {
    public long minimumSteps(String s) {
        long cnt=0,ans=0;
        char[] help = s.toCharArray();
        for(int i=s.length()-1;i>-1;i--){
            if(help[i]=='0')cnt++;
            else ans+=cnt;
        }return ans;
    }
}