class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        strList = str.split(' ')
        if len(pattern)!=len(strList):
            return False
        M = {}
        S = set()
        strIndex = 0
        for ch in pattern:
            if M.get(ch) is None:
                if strList[strIndex] in S:
                    return False
                else:
                    M[ch] = strList[strIndex]
                    S.add(strList[strIndex])
            else:
                if M[ch] != strList[strIndex]:
                    return False
            strIndex += 1

        return True
