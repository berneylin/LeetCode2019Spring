#include<vector>
using namespace std;

class Solution {
public:
    int totalArea;//总面积
    vector<int> rectToLine;//将二维平面中矩形面积的大小转化为一维线段，建立映射
    vector<vector<int>> myRects;//复制矩形
    Solution(vector<vector<int>> rects) {
        myRects = rects;
        totalArea= 0;
        for (const auto& rect : rects) {
            totalArea+= (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);//计算面积
            rectToLine.push_back(totalArea);//建立一个映射将[上一次total_area, total_area + 当前矩形面积]映射为这个矩形
        }
    }
    
    vector<int> pick() {
        int randomArea = rand() % totalArea+ 1;//随机生成一个数[1, total_area]
        int index = 0, rectsSize = rectToLine.size();//根据这个数映射出这个被选中的矩形
        // while (index < rectsSize && randomArea > rectToLine[index]){
        //     index += 1;
        // }
        int l = 0, r = rectToLine.size()-1;
        while(l<r){
            // 找右边界
            int m = l + (r-l) / 2;
            if(randomArea <= rectToLine[m]){
                r = m;
            }else{
                l = m+1;
            }
        }
        index = l;

        //在这个选中的矩形中随机选出一个点
        int dis_x = rand() % (myRects[index][2] - myRects[index][0] + 1);
        int dis_y = rand() % (myRects[index][3] - myRects[index][1] + 1);
        return {myRects[index][0] + dis_x, myRects[index][1] + dis_y};
    }
}; 