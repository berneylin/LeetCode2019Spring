#include<map>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, sLen = s.length();
        int ans = 0;
        map<char, int> chMap;

        while (r<sLen)
        {
            if(chMap.find(s[r])==chMap.end()) {
                // map初始化
                chMap.insert(make_pair(s[r], 0));
            }
            if (chMap[s[r]] == 1) {
                // 重复了
                // 先更新答案
                ans = ((r-l)>ans)?r-l:ans;
                while(chMap[s[r]] == 1) {
                    // 向前移动l指针并减少字母出现的次数
                    chMap[s[l]] = 0;
                    l++;
                }
            }
            chMap[s[r]] = 1;
            r++;
        }
        ans = ((r-l)>ans)?r-l:ans;
        
        return ans;
    }
};

// abcabcbb