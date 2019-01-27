#include<climits>
#include<cstdio>
using namespace std;

// class Solution {
// public:
    int reverse(int x) {
        long ret = 0;
        bool negFlag = x<0?true:false;
        long tmp = negFlag?-x:x;

        while(tmp){
            ret *= 10;
            ret += tmp%10;
            tmp/=10;
        }
        if(negFlag){
            ret *= -1;
        }
        if(ret>INT_MAX||ret<INT_MIN) ret = 0;
        return (int)ret;
    }
// };

int main(void){
    int x;
    scanf("%d", &x);
    printf("%d", reverse(x));
    return 0;
}