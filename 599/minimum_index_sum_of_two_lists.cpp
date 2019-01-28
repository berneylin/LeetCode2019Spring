#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> M;
        int len1 = list1.size(), len2 = list2.size();
        for(int i=0;i<len1;i++){
            M.insert(make_pair(list1[i], i));
        }
        int minIdxSum = len1 + len2;  // initialize with a large num that cannot reach


        // find the minimum summation of the intersection
        for(int i=0;i<len2;i++){
            if(M.find(list2[i])!=M.end()){
                int thisIdxSum = M[list2[i]] + i;
                minIdxSum = minIdxSum>thisIdxSum?thisIdxSum:minIdxSum;
            }
        }
        vector<string> ret;

        // push all qualified string elements into the return vector
        for(int i=0;i<len2;i++){
            if(M.find(list2[i])!=M.end() && M[list2[i]]+i==minIdxSum){
                ret.push_back(list2[i]);
            }
        }
        return ret;
    }
};