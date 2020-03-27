class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        s_len = len(s)
        mem_list = [False for _ in range(s_len+1)]
        mem_list[0] = True
        for i in range(1, s_len+1):
            for word in wordDict:
                if mem_list[i-len(word)] and s[:i].endswith(word):
                    mem_list[i] = mem_list[i-len(word)]
        return mem_list[s_len]