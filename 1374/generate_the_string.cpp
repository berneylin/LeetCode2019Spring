#include<string>
using namespace std;


class Solution {
public:
    string generateTheString(int n) {
        if(n<=0) return "";
        string ans;
        if(n&1){
            ans = string(n, 'a');
        }else{
            ans= string(n-1, 'b');
            ans.push_back('a');
        }
        return ans;
    }
};