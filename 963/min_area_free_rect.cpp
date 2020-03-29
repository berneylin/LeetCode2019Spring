#include<vector>
#include<cmath>
using namespace std;

class Line{
public:
    int mX1, mX2, mY1, mY2;
    double lengthSquare;
    double midX, midY;

    Line(int x1, int y1, int x2, int y2){
        mX1 = x1;
        mX2 = x2;
        mY1 = y1;
        mY2 = y2;

        lengthSquare = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        midX = (double)(x1) + ((double)(x2)-(double)(x1))/2;
        midY = (double)(y1) + ((double)(y2)-(double)(y1))/2;
    }
};
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        vector<Line> lineVec;
        int minSize = 0;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                const Line &thisLine = Line(points[i][0], points[i][1], points[j][0], points[j][1]);
                for(const Line &eachLine: lineVec){
                    if(eachLine.lengthSquare == thisLine.lengthSquare && 
                        eachLine.midX == thisLine.midX && 
                        eachLine.midY == thisLine.midY)
                    {
                        // 能够组成矩形，计算面积
                        double l1 = (eachLine.mX1 - thisLine.mX1)*(eachLine.mX1 - thisLine.mX1)+
                                         (eachLine.mY1 - thisLine.mY1)*(eachLine.mY1 - thisLine.mY1);
                        double l2 = (eachLine.mX2 - thisLine.mX1)*(eachLine.mX2 - thisLine.mX1)+
                                         (eachLine.mY2 - thisLine.mY1)*(eachLine.mY2 - thisLine.mY1);
                        double thisSize = sqrt(l1 * l2);
                        if(minSize==0 || thisSize<minSize) minSize = thisSize;
                    }
                }
                lineVec.push_back(thisLine);
            }
        }

        return minSize;
    }
};