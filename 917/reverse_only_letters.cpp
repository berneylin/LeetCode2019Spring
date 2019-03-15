class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(S.empty()) return S;
        const int SIZE = S.size();
        string ans(SIZE);
        for(int i=0;i<SIZE;i++){
            if((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z')) continue;  // letters
            ans[i] = S[i];
        }
        int idx = SIZE - 1;
        while(idx>=0 && !((S[idx]>='a'&&S[idx]<='z')||(S[idx]>='A'&&S[idx]<='Z'))) idx--;  // find the first position to insert letter
        for(int i=0;i<SIZE;i++){
            if(!((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z'))) continue;  // not letter
            ans[idx--] = S[i];
            while(idx>=0 && !((S[idx]>='a'&&S[idx]<='z')||(S[idx]>='A'&&S[idx]<='Z'))) idx--;  // find the next position to insert letter
        }
        return ans;
    }
};