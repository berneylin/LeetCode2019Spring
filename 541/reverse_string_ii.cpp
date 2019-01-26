#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        string ret = s;
        int strLength = s.size();
        if(strLength<2*k&&strLength>=k){
            reverse(ret.begin(), ret.begin()+k);
        }else{
            int twoSubNums = strLength / (2*k);
            int cnt = 0;
            string::iterator it;
            for(it=ret.begin();cnt<twoSubNums;cnt++, it+=2*k){
                reverse(it, it+k);
            }
            int remainNums = strLength % (2*k);
            if(remainNums>=k){
                reverse(it, it+k);
            }else{
                reverse(it, ret.end());
            }
        }
        return ret;
    }
};