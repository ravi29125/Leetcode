class Solution:
    def convertDateToBinary(self, date: str) -> str:
        y=bin(int(date[:4]))
        m=bin(int(date[5:7]))
        d=bin(int(date[8:10]))
        return y[2:]+"-"+m[2:]+"-"+d[2:]
        