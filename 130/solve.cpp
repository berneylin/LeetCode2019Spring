#include<vector>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;

        for(int i=0; i<board.size(); i++){
            if(board[i][0]=='O')
                dfs(board, i, 0);
            if(board[i][board[0].size()-1] == 'O')
                dfs(board, i, board[0].size()-1);
        }

        for(int j=0; j<board[0].size(); j++){
            if(board[0][j]=='O')
                dfs(board, 0, j);
            if(board[board.size()-1][j]=='O')
                dfs(board, board.size()-1, j);
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                if(board[i][j]=='o')
                    board[i][j] = 'O';
            }
        }
        
    }

    void dfs(vector<vector<char> > &board, int i, int j){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!='O')
            return;
        
        board[i][j] = 'o';

        dfs(board, i+1, j);
        dfs(board, i, j+1);
        dfs(board, i-1, j);
        dfs(board, i, j-1);
    }
};