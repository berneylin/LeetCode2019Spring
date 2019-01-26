#include<set>
#include<string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels;
        vowels.insert('a');vowels.insert('e');vowels.insert('i');vowels.insert('o');vowels.insert('u');
        vowels.insert('A');vowels.insert('E');vowels.insert('I');vowels.insert('O');vowels.insert('U');
        char tmp;
        string::iterator itLeft = s.begin(), itRight = s.end()-1;

        while(itLeft<itRight){
            while(itLeft<itRight && vowels.find(*itLeft)==vowels.end()) itLeft++;
            while(itLeft<itRight && vowels.find(*itRight)==vowels.end()) itRight--;
            tmp = *itLeft;
            *itLeft = *itRight;
            *itRight = tmp;
            itLeft++;
            itRight--;
        }

        return s;
    }
};