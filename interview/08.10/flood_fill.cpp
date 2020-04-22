#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int> > ansVec = image;
        if(image.empty() || image[0].empty()) return ansVec;
        int rowNum = image.size(), colNum = image[0].size();

        vector<vector<bool> > visited(rowNum, vector<bool>(colNum, false));
        rawColor = image[sr][sc];
        targetColor = newColor;
        dfs(image, sr, sc, visited);
        return image;
    }

    void dfs(vector<vector<int> > &image, int rIdx, int cIdx, vector<vector<bool> > &visited){
        if(rIdx<0 || rIdx>=image.size() || cIdx<0 || cIdx>=image[0].size() || visited[rIdx][cIdx] || image[rIdx][cIdx]!=rawColor) return;
        image[rIdx][cIdx] = targetColor;
        visited[rIdx][cIdx] = true;
        dfs(image, rIdx+1, cIdx, visited);
        dfs(image, rIdx-1, cIdx, visited);
        dfs(image, rIdx, cIdx+1, visited);
        dfs(image, rIdx, cIdx-1, visited);
    }

    
private:
    int rawColor;
    int targetColor;
};