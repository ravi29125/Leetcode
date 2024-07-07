class Solution:
    def validStrings(self, n: int) -> List[str]:
        if n == 1:
            return ["0","1"]
        ans = ["0","1"]
        for k in range(1,n):
            cur = []
            for i in ans:
                if i[-1] == "0":
                    cur.append(i+'1')
                else:
                    cur.append(i+'0')
                    cur.append(i+'1')
            ans = cur
        return ans