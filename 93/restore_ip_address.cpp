#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()<4) return ans;
        if(s[0]=='0') return ans;
        int sIdx = 0, dotCnt = 0;
        vector<string> tmp;
        dfs(tmp, 0, ans, s);
        return ans;
    }

    void dfs(vector<string> &tmp, int sIdx, vector<string> &ans, const string &s){
        if(tmp.size()==4){  // 如果已经有了4个数了
            if(sIdx!=s.size()) return; // 如果没用完原字符串 不合格
            // 下面对ip的合法性再做判断
            for(int i=0;i<4;i++){  // 遍历tmp字符串数组
                if(tmp[i].size()==3){
                    int num = (tmp[i][0]-'0') * 100 + (tmp[i][1]-'0') * 10 + (tmp[i][2]-'0');
                    if(num>255) return; // 大于255的数 非法
                }
                if(tmp[i].size()>1&&tmp[i][0]=='0') return;  // 如果不是1位数 但是是0开头 非法
            }
            ans.push_back(tmp[0]+"."+tmp[1]+"."+tmp[2]+"."+tmp[3]);
        }else{
            for(int i=1;i<=3;i++){
            tmp.push_back(s.substr(sIdx, i)); 
            dfs(tmp, sIdx+i, ans, s);
            tmp.pop_back();
            }
        }
        
    }







};