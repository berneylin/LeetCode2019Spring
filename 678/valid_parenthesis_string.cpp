class Solution {
public:
    bool checkValidString(string s) {
        if(s.empty()) return true;
        int leftCnt = 0, starCnt = 0, rightCnt = 0;
        bool ansFlag = true;
        for(string::iterator it=s.begin();ansFlag && it!=s.end();it++){
            if(*it=='(') leftCnt++;
            else if(*it=='*') starCnt++;
            else{
                if(leftCnt) leftCnt--;
                else{
                    if(starCnt) starCnt--;
                    else ansFlag = false;
                }
            }
        }
        if(ansFlag && leftCnt) ansFlag = starCnt>=leftCnt;
        starCnt = 0;
        for(string::reverse_iterator rit=s.rbegin();ansFlag && rit!=s.rend();rit++){
            if(*rit==')') rightCnt++;
            else if(*rit=='*') starCnt++;
            else{
                if(rightCnt) rightCnt--;
                else{
                    if(starCnt) starCnt--;
                    else ansFlag = false;
                }
            }
        }
        if(ansFlag && rightCnt) ansFlag = starCnt>= rightCnt;
        return ansFlag;
    }
};