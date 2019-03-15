#include<map>
using namespace std;

class Solution {
public:
    string convertNum2Str(long x){
        if(x==0) return "0";
        string ans = "";
        while(x){
            ans = (char)(x%10+'0') + ans;
            x/=10;
        }
        return ans;
    }
    string fractionToDecimal(int numerator, int denominator) {
        // return the string format of numerator/denominator
        if(numerator==0) return "0";
        if(denominator==0) return "Nan";
        string ans = "";
    
        long _numerator = numerator;
        long _denominator = denominator;
        
        bool negFlag = (_numerator<0&&_denominator>0) || (_numerator>0&&_denominator<0);
        // 统一按正数处理
        _numerator = _numerator>0?_numerator:-_numerator;
        _denominator = _denominator>0?_denominator:-_denominator;
        if(negFlag){  
            ans.insert(ans.begin(), '-');
        }
        ans += convertNum2Str(_numerator/_denominator);
        if(_numerator%_denominator==0) return ans;  // 无小数部分 不需要小数点
        ans += '.';
        _numerator %= _denominator;
        string fracPart = "";
        map<long, int> remainders;
        
        while(_numerator){
            if(remainders.find(_numerator)!=remainders.end()){
                fracPart.insert(remainders[_numerator], "(");
                fracPart.push_back(')');
                break;
            }
            remainders[_numerator] = fracPart.size();
            fracPart += convertNum2Str(_numerator*10 / _denominator);
            _numerator = (_numerator*10)%_denominator;
        }
        
        return ans+fracPart;
    }
};