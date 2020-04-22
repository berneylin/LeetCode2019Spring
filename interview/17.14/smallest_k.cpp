#include<vector>
using namespace std;


class Solution {
public:
    void quickSort(vector<int> &arr, int lhs, int rhs, const int &targetK){
        if(lhs>=rhs) return;
        int pivot = arr[lhs];
        int lo = lhs, hi = rhs;
        while(lo<hi){
            while(lo<hi && arr[hi]>=pivot) hi--;
            while(lo<hi && arr[lo]<=pivot) lo++;
            if(lo<hi){
                int x = arr[hi];
                arr[hi] = arr[lo];
                arr[lo] = x;
            }
        }
        arr[lhs] = arr[lo];
        arr[lo] = pivot;
        if(lo==targetK) return;
        else if(lo>targetK) quickSort(arr, lhs, lo-1, targetK);
        else if(lo<targetK) quickSort(arr, lo+1, rhs, targetK);
    }
    
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty() || k==0) return {};
        if(k>arr.size()) return arr;

        quickSort(arr, 0, arr.size()-1, k);
        arr.resize(k);

        return arr;
    }
};