#include<set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> S;
        int tmp = n, sum=0;
        bool ansFlag = true;
        while(ansFlag && tmp!=1){
            while(tmp){
                sum += (tmp%10)*(tmp%10);
                tmp /= 10;
            }
            tmp = sum;
            sum = 0;
            if(S.find(tmp)!=S.end()) ansFlag=false;
            else S.insert(tmp);
        }
        return ansFlag;
    }
};