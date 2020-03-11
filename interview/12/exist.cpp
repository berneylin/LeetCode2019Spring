#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;


class Solution {
public:
    int move[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    bool exist(vector<vector<char>>& board, string word) {
        bool rtnFlag = false;
        
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                if (board[i][j] == word[0]) {
                    vector<vector<int> > visited(board.size(), vector<int>(board[0].size(), 0));
                    rtnFlag = dfs(board, word, i, j, 0, visited);
                    if (rtnFlag)
                        break;
                }
            }
            if (rtnFlag)
                break;
        }
        return rtnFlag;
    }

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int wordIdx, vector<vector<int> > &visited) {
        if (!word.empty() && wordIdx == word.size())
            return true;
        if (word.empty() || i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[wordIdx] || visited[i][j])
            return false;
        int nextI = 0, nextJ = 0;
        bool rtnFlag = false;
        visited[i][j] = 1;
        for (int moveIdx=0; moveIdx<4; moveIdx++) {
            nextI = move[moveIdx][0] + i;
            nextJ = move[moveIdx][1] + j;
            rtnFlag |= dfs(board, word, nextI, nextJ, wordIdx+1, visited);
            if (rtnFlag)
                break;
        }
        visited[i][j] = 0;
        return rtnFlag;
    }
};