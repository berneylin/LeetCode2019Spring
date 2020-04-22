#include<string>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    if(a==0) return false;
    if(b==0) return true;

    string aPre = to_string(a) + to_string(b);
    string bPre = to_string(b) + to_string(a);
    return aPre > bPre;
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return "";
        bool zeroFlag = true;
        for(const int &num: nums){
            zeroFlag = num == 0;
            if(!zeroFlag) break;
        }
        if(zeroFlag) return "0";
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        for(const int &num: nums) 
            ans += to_string(num);
        return ans;
    }
};