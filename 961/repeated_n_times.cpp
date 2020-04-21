#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> tmp;
        int ans = 0;
        for(const int &num: A){
            if(tmp.find(num)!=tmp.end()){
                ans = num;
                break;
            }
            tmp.insert(num);
        }
        return ans;
    }
};