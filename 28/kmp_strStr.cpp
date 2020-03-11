#include<string>
#include<iostream>
#include<vector>

using namespace std;

int findCommonPrePostLength(const string &s)
{
    int sLength = s.length();
    if (sLength==0 || sLength==1)
        return 0;
    int subStrLength = sLength-1;
    int rtnLength = 0;
    while(subStrLength)
    {
        bool failFlag = false;
        for(int i=0; i < subStrLength; i++){
            if (s[i] != s[sLength - subStrLength + i])
            {
                failFlag = true;
                break;
            }
        }
        if (!failFlag) {
            rtnLength = subStrLength;
            break;
        }
        subStrLength--;
    }
    return rtnLength;
}

vector<int> constructNextArr(const string &needle)
{
    int sLength = needle.length();
    vector<int> rtnV;
    for (int i = 0; i < sLength; i++) {
        rtnV.push_back(findCommonPrePostLength(needle.substr(0, i+1)));
    }
    return rtnV;
}

int strStr(string haystack, string needle) {
    vector<int> next = constructNextArr(needle);
    int i = 0, j = 0, hLength = haystack.length(), nLength = needle.length();
    if(nLength == 0)
        return 0;
    if(hLength < 1 || nLength > hLength)
        return -1;
    for (int idx = 0; idx < nLength; idx++) cout << next[idx] << " ";
    cout << endl;
    while(i < hLength){
        cout << haystack[i] << needle[j] << endl;
        if (haystack[i]==needle[j])
        {
            i++;
            j++;
        }else{
            if (j==0) {
                i++;
            }else{
                j = next[j-1];
            }
        }
        if(j==nLength)
            return i-nLength;
    }
    return -1;
}


int main(void){
    string testHaystack, testNeedle;
    cin >> testHaystack;
    cin >> testNeedle;
    cout << "Haystack: " << testHaystack << endl;
    cout << "Needle: " << testNeedle << endl;
    cout << strStr(testHaystack, testNeedle) << endl;
    return 0;
}

