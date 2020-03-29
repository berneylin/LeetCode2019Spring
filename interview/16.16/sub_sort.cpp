#include<vector>
using namespace std;

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> ansVec(2, -1);
        if(array.size()<=1) return ansVec;
        int last = -1, first = -1;
        int max = array[0], min = array[array.size()-1];
        for(int i=0; i<array.size(); i++){
            if(array[i] < max){
                last = i;
            }else{
                max = array[i]>max?array[i]:max;
            }

            if(array[array.size()-1-i] > min){
                first = array.size()-1-i;
            }else{
                min = array[array.size()-1-i]<min?array[array.size()-1-i]:min;
            }
        }

        ansVec[0] = first;
        ansVec[1] = last;
        return ansVec;
    }
};