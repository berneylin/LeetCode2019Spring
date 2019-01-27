int climbStairs(int n) {
    int tmp, ret, iter;
    tmp = 1;  /* Fib(0) */
    ret = 1;  /* Fib(1) */
    iter = 1;  /* initialize */

    while(iter<n){
        ret = ret + tmp;
        tmp = ret - tmp;
        iter++;
    }
    return ret;
}