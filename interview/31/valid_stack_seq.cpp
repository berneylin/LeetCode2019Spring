#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        for (int i=0; i<pushed.size(); ++i) {
            _tmpStack.push(pushed[i]);
            while(_tmpStack.size() && _tmpStack.top() == popped[j]) {
                _tmpStack.pop();
                j++;
            }
        }
        return j==popped.size();
    }
private:
    stack<int> _tmpStack;
};