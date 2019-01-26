#include<stack>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;  // negative number is always not-palindrome
        stack<int> S;
        int x_digits = getNumberLength(x);
        
        for(int i=0;i<(x_digits>>1);i++){
            // save the low order half part into the stack
            S.push(x%10);
            x /= 10;
        }

        if (x_digits&1) {
            // x is a odd-digits number
            // overlook the middle digit
            x/=10;
        }

        while(!S.empty()){
            if(S.top() != (x%10)){
                return false;
            }else{
                S.pop();
                x /= 10;
            }
        }
        return true;
    }

private:
    int getNumberLength(int x){
        // return the length(digits) of a decimal number
        int len = 1;  // a number always owns at least one digit
        x /= 10;
        while(x){
            len++;
            x /= 10;
        }
        return len;
    }
};