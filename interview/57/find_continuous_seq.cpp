#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> ansVec;
        int thisSum = 3, l = 1, r = 2;
        int maxNum = target & 1 ? target / 2 + 1 : target / 2;
        while (r <= maxNum)
        {
            if (thisSum == target)
            {
                vector<int> tmpVec;
                for (int i = l; i <= r; i++)
                {
                    tmpVec.push_back(i);
                }
                ansVec.push_back(tmpVec);
                thisSum -= l;
                l++;
            }
            else if (thisSum < target)
            {
                r++;
                thisSum += r;
            }
            else if (thisSum > target)
            {
                thisSum -= l;
                l++;
            }
        }
        return ansVec;
    }
};