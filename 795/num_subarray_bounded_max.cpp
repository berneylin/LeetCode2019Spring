#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        if(A.empty()) return 0;
        int lhs = -1, rhs = -1, max = 0x80000000, ans = 0;

        // [1, 2, 1, 4, 3] 2, 3
        for(int i=0; i<A.size(); i++){
            int &thisNum = A[i];
            if(thisNum<=R && lhs == -1){
                // 开始记录区间端点
                lhs = i;
                rhs = i;
            }
            else if(lhs!=-1 && thisNum<=R){
                // 更新区间的右端点
                rhs = i;
            }else if(thisNum>R){
                // 当前数比R还要大，区间要结束了
                if(max>=L && rhs!=-1){
                    // 如果区间内最大的数符合条件，更新ans
                    ans += ((rhs-lhs+1)*(rhs-lhs+2))/2;
                    // 去掉不符合要求的子数组
                    for(int i=lhs; i<=rhs; i++){
                        for(int j=i; j<=rhs; j++){
                            if(A[j]>=L) break;
                            ans--; 
                        }
                    }
                }
                // 重置状态
                lhs = -1, rhs = -1, max = 0x80000000;
            }
            if(lhs!=-1){
                // 当前在可能区间内，更新区间内最大值
                max = max>thisNum?max:thisNum;
            }
        }

        // 尾部处理, 相当于在数组后面append一个R+1
        if(lhs!=-1 && max>=L) {
            ans += (rhs-lhs+1)*(rhs-lhs+2)/2;
            // 去掉不符合要求的子数组
            for(int i=lhs; i<=rhs; i++){
                for(int j=i; j<=rhs; j++){
                    if(A[j]>=L) break;
                    ans--; 
                }
            }
        }

        return ans;
    }
};