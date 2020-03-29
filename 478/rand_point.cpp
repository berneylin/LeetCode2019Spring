class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        radius = radius;
        radiusSquare = radius*radius;
        x = x_center;
        y = y_center;
        left = x_center - radius;
        right = x_center + radius;
        up = y_center + radius;
        down = y_center - radius;
    }
    
    vector<double> randPoint() {
        vector<double> ans;
        do{
            double pointX = genRand(left, right);
            double pointY = genRand(down, up);
            if(checkIn(pointX, pointY)){
                ans.push_back(pointX);
                ans.push_back(pointY);
                break;
            }
        }while(true);
        return ans;
    }

private:
    double radius;
    double radiusSquare;
    double x; 
    double y;
    double left, right, up, down;

    bool checkIn(double pointX, double pointY){
        double dist = (pointX-x)*(pointX-x) + (pointY-y)*(pointY-y);
        return dist<=radiusSquare;
    }

    double genRand(double a, double b){
        // generate random number in [a, b]
        return a+ (b-a)*(rand() / double(RAND_MAX));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */x