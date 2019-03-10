#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    map<char, int> M;

    bool cmp(const string &a, const string &b){
        const int ASize = a.size(), BSize = b.size();
        const int SIZE = ASize<BSize?ASize:BSize;
        for(int i=0;i<SIZE;i++) {
            if(M[a[i]]<M[b[i]]) return true;
            else if(M[a[i]]>M[b[i]]) return false;
        }
        // 此时A和B中拥有相同前缀
        return ASize<BSize?true:false;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        int orderSize = order.size(), wordsSize = words.size();
        for(int i=0;i<orderSize;i++) M.insert(pair<char, int>(order[i], i));
        bool isLegal = true;
        bool retFlag = true;
        for(int i=0;i<wordsSize - 1 && retFlag;i++){
            for(int j=i+1;j<wordsSize && retFlag;j++){
                retFlag = cmp(words[i], words[j]);
            }
        }
        return retFlag;
    }
};