class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int sLength = s.size();
        bool wordFlag = true;
        for(int i=0;i<sLength;i++){
            if(s[i]!=' '&&wordFlag){
                cnt ++;
                wordFlag = false;
            }
            if(s[i]==' '&&!wordFlag){
                wordFlag = true;
            }
        }
        return cnt;
    }
};