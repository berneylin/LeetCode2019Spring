#include<vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int arrSize = arr.size();
        int idx = 0;
        while(idx<arrSize){
            if(arr[idx]==0 && idx!=(arrSize-1)){
                for(int i=arrSize-2; i>=idx+1; i--){
                    arr[i+1] = arr[i];
                }
                arr[idx+1] = 0;
                idx += 2;
            }
            else idx++;
        }
    }
};