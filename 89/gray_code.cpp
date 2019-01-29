class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int graySize = 1<<n;  // the size of the gray code vector is 2^n
        for(int i=0;i<graySize;i++){
            if(i==0) ret.push_back(0);
            else{
                int pre = ret[i-1];
                int oneCount = 0;
                while(pre){
                    oneCount += (pre&1);
                    pre>>=1;
                }
                if(!(oneCount&1)){  // one counts odd number, change the lowest bit 0 <-> 1
                    if(ret[i-1]&1) ret.push_back(ret[i-1]&0xFFFFFFFE);  // end with 1
                    else ret.push_back(ret[i-1]|1);  // end with 0
                }else{  // one counts even number, change the bit which ajacently higher than the lowest 1
                    pre = ret[i-1];
                    oneCount = 0;
                    while(!(pre&1)){
                        pre>>=1;
                        oneCount++;
                    }
                    pre>>=1;
                    if(pre&1) pre = pre&0xFFFFFFFE;
                    else pre = pre|1;
                    pre<<=1;
                    pre++;
                    pre<<=oneCount;
                    ret.push_back(pre);
                }
            }
        }
        return ret;
    }
};