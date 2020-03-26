#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        partition(arr, 0, arr.size()-1, k);
        vector<int> ansVec;
        for(int i = 0; i < k; ++i) {
            ansVec.push_back(arr[i]);
        }
        return ansVec;
    }

    void partition(vector<int> &arr, int l, int r, int k) {
        if (l>=r) return;
        int i = l, j = r, tmpNum = arr[l];
        while(i<j) {
            while(i<j && arr[j] >= tmpNum) j--;
            while(i<j && arr[i] <= tmpNum) i++;
            if (i<j){
                int swapNum = arr[i];
                arr[i] = arr[j];
                arr[j] = swapNum;
            }
        }
        arr[l] = arr[i];
        arr[i] = tmpNum;
        
        if (i==k) return;
        else if (i > k) partition(arr, l, i-1, k);
        else if (i < k) partition(arr, i+1, r, k);
    }
};