class Solution {
public:
    string originalDigits(string s) {
    // 为了查找每个数字需要减少其计数的字母
    // 按照 vt 的顺序查找，进行了尽可能的优化
    const vector<string> numbers = {
        "ro",   // 0
        "",     // 1
        "o",    // 2
        "",     // 3
        "for",  // 4
        "i",    // 5
        "si",   // 6
        "",     // 7
        "i",    // 8
        ""      // 9
    };
        
    // 找到数字的顺序
    const vector<pair<char, int>> vt = {
        {'z', 0},
        {'w', 2},
        {'u', 4},
        {'f', 5}, 
        {'x', 6}, 
        {'s', 7}, 
        {'g', 8},
        {'i', 9},
        {'r', 3},
        {'o', 1}
    }; 
        
    // 为字母计数
    int table[26]{};
    for(char c : s)
        ++table[c - 'a'];
        
        
    string rt;
        
    // 查找数字，并减少对应字母的计数
    for(const auto &i : vt) {
        if(int n = table[i.first - 'a']; n > 0) {
            rt.append(n, '0' + i.second);
            for(char c : numbers[i.second])
                table[c - 'a'] -= n;
        }
        }
        
    sort(rt.begin(), rt.end());
    return move(rt);
    }
};