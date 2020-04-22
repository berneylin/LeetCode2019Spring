#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); ++i)
        {
            auto t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(const auto& iter : mp)
        {
            res.push_back(std::move(iter.second));
        }
        return res;
    }
};