class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n){
            ans.insert(ans.begin(), numToChar((n-1)%26));
            if(n==26) return ans;
            if(n%26==0) n--;
            n/=26;
        }
        return ans;
    }
private:
    inline char numToChar(int n) {
        return n==0?'Z':(char)('A'+n);
    }
};