#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, startIdx = 0, curTank = 0;
        for(int i=0; i<gas.size(); i++){
            curTank += (gas[i] - cost[i]);
            gasSum += (gas[i] - cost[i]);
            if(curTank<0){
                startIdx = i+1;
                curTank = 0;
            }
        }
        return gasSum<0?-1:startIdx;
    }
};