class Solution {
    private HashSet<String> st;
    public boolean wordBreak(String s, List<String> wordDict) {
        st=new HashSet<>();
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            st.add(wordDict.get(i));
        }
        n=s.length();
        boolean[] dp=new boolean[n+1];
        dp[0]=true;
        for(int i=1;i<=n;i++){
            dp[i]=false;
            for(int j=0;j<i;j++){
                if(dp[j] && st.contains(s.substring(j,i))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
}