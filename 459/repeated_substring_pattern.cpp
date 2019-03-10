class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()<=1) return false;
        const int sSize = s.size();
        bool ansFlag = false;
        for(int i=2;i<=sSize;i++){// 要把sSize分成的份数
            if(sSize%i==0){  // 如果能均分
                const int subStrLen = sSize/i;  // 均分后的每个子串的长度
                int subStrIdx;
                for(subStrIdx=0;subStrIdx<sSize-subStrLen;subStrIdx+=subStrLen){
                    int j;
                    for(j=0;j<subStrLen;j++){
                        if(s[subStrIdx+j]!=s[subStrIdx+j+subStrLen]) break;
                    }
                    if(j!=subStrLen) break;
                }
                if(subStrIdx==sSize-subStrLen) {
                    ansFlag=true;
                    break;
                }
            }
        }
        return ansFlag;
    }
};