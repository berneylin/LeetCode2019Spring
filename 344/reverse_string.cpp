class Solution {
public:
    void reverseString(vector<char>& s) {
        int strLength = s.size();
        int index = 0;
        int halfStrLength = strLength>>1;
        char tmp;
        while(index<halfStrLength){
            tmp = s[index];
            s[index] = s[strLength-1-index];
            s[strLength-1-index] = tmp;
            index ++;
        }
    }
};