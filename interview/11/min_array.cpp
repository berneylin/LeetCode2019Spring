class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty())
            return 0;
        int left = 0, right = numbers.size() - 1, mid = 0;
        while(left < right){
            mid = left + ((right - left) >> 1);
            if (numbers[mid] < numbers[right]) right = mid;
            else if (numbers[mid] > numbers[right]) left = mid + 1;
            else right--;
        }
        return numbers[left];
    }
};