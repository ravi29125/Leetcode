class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        
        m = sorted(meetings)

        cnt = 0
        s = 0

        for i in range(len(meetings)):
            if m[i][0]>s:
                cnt += m[i][0] - s - 1

            s = max(s, m[i][1])

        return cnt+days-s