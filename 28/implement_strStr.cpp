class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLen = needle.size();
        int haystackLen = haystack.size();
        if(!needleLen) return 0;
        int ret = -1;
        for(int i=0;i<haystackLen-needleLen+1;i++){
            bool thisCmp = true;
            for(int j=0;j<needleLen;j++){
                if(haystack[i+j]!=needle[j]){
                    thisCmp = false;
                    break;
                }
            }
            if(thisCmp){
                ret = i;
                break;
            }
        }
        return ret;
    }
};