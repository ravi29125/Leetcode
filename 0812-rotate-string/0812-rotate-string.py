class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        for i in range(len(s)):
            if(s==goal):
                return True
            s=s[len(s)-1]+s[:len(s)-1]
        return False