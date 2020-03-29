// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
int rand7(void){
    return 0;
}

// easy version
class Solution {
public:
    int rand10() {
        int row = rand7(), col = rand7();
        int thisNum = (row-1)*7+col;
        while(thisNum>40){
            row = rand7();
            col = rand7();
            thisNum = (row-1)*7 + col;
        }
        return thisNum%10+1;
    }
};

// hard version
class Solution {
public:
    int rand10() {
        int ans = 0;
        do{
            ans = (rand7()-1)*7+rand7();  // 生成 [1-49] 的均匀分布
            if(ans<=40) break;

            // ans在[41-49]中 转换到[1-9]
            ans -= 40;
            ans = (ans-1) * rand7();  // 生成 [1-63] 的均匀分布

            if(ans<=60) break;
            // ans 在[61-63]中 转换到[1-3]
            ans -= 60;
            ans = (ans-1) * rand7();  // 生成 [1-21] 的均匀分布

            if(ans<=20) break;
            // ans为21，转换只能到1 没啥用了 重头再来吧
        }while(ans<1||ans>10);

        return (ans-1)%10+1;
    }
};