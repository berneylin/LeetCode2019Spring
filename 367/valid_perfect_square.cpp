class Solution {
public:
    bool isPerfectSquare(int num) {
        bool isPerfect = false;
        int left = 1;
        int right = num;
        int mid;
        while(left<=right){
            mid = left + (right - left) / 2;
            if(mid*mid == num){
                isPerfect = true;
                break;
            }else{
                if(num/mid<mid) right = mid-1;
                else left = mid+1;
            }
        }
        return isPerfect;
    }
};