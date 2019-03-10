#include<stack>
#include<list>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        const int aSize = findNums.size(), bSize = nums.size();
        vector<int> ans(aSize);
        list<int> tmp;
        if(aSize==0) return ans;
        stack<int> S;
        
        for(int i=0;i<bSize;i++) S.push(nums[i]);
        while(!S.empty()){
            if(find(findNums.begin(), findNums.end(), S.top())!=findNums.end()){
                int index = distance(findNums.begin(), find(findNums.begin(), findNums.end(), S.top()));
                list<int>::iterator it = tmp.begin();
                while(it!=tmp.end()){
                    if(*it>S.top()){
                        ans[index] = *it;
                        break;
                    }
                    it++;
                }
                if(it==tmp.end()) ans[index] = -1;
            }
            tmp.push_front(S.top());
            S.pop();
        }
        return ans;
    }
};