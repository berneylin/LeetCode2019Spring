#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string str) {
        int strLen = str.size();
        unordered_map<char, int> M;
        M.insert(make_pair<char, int>('I', 1));
        M.insert(make_pair<char, int>('V', 5));
        M.insert(make_pair<char, int>('X', 10));
        M.insert(make_pair<char, int>('L', 50));
        M.insert(make_pair<char, int>('C', 100));
        M.insert(make_pair<char, int>('D', 500));
        M.insert(make_pair<char, int>('M', 1000));
        int ret = 0;
        for(int i=0;i<strLen;i++){
            if(i==strLen-1) ret+=M[str[i]];
            else{
                if(M[str[i]]<M[str[i+1]]){
                    ret += M[str[i+1]] - M[str[i]];
                    i++;
                }else{
                    ret += M[str[i]];
                }
            }
        }
        return ret;
    }
};