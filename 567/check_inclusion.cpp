#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26, 0);
        vector<int> m2(26, 0);

        for(char ch: s1){
            m1[ch-'a']++;
        }

        int l = 0;  // 滑动窗口的左边界，初始为0
        int r = s1.size()-1;  // 滑动窗口的右边界，初始为s1的长度

        while(r<s2.size()){
            if(l==0){
                // m2初始化
                for(int i=l; i<=r; i++){
                    m2[s2[i]-'a']++;
                }
            }
            if (m1 == m2) {
                return true;
            }

            // 更新m2
            l++;
            m2[s2[l-1]-'a']--;

            r++;
            if(r<s2.size()) m2[s2[r]-'a']++;
        }

        return false;

    }
};