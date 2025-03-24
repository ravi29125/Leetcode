class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings,(a,b)->Integer.compare(a[0],b[0]));
        int n=meetings.length;
        int st=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(meetings[i][0]>st){
                ans+=(meetings[i][0]-st-1);
                st=meetings[i][1];
            }else st=Math.max(st,meetings[i][1]);
        }return ans+days-st;
    }
}