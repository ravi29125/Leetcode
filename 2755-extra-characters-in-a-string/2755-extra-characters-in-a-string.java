class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n=s.length();
        //boolean[] arr=new boolean[n+1];
        long[] dp=new long[n+1];
        for(int i=0;i<=n;i++){
           // arr[i]=false;
            dp[i]=Integer.MAX_VALUE;
        }
        int m=dictionary.length;
        HashSet st = new HashSet<>();
        for(int i=0;i<m;i++)st.add(dictionary[i]);
       // arr[0]=true;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j=0;j<i;j++){
                if(st.contains(s.substring(j,i))){
                    dp[i]=Math.min(dp[i],dp[j]);
                }
            }
        }return (int)dp[n];
    }
}