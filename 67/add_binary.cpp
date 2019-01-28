class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size();
        string ret = "";

        if(aLen<bLen){  // uniform handle: make string a always the longer one between the two strings
            ret = b;
            b = a;
            a = ret;
            ret = "";
            aLen = aLen ^ bLen;
            bLen = bLen ^ aLen;
            aLen = aLen ^ bLen;
        }

        bool currBitSum, carry = false;
        for(int i=1;i<=bLen;i++){
            currBitSum = a[aLen-i]!=b[bLen-i];
            currBitSum = carry?(!currBitSum):currBitSum;
            carry = carry?((a[aLen-i]=='1')||(b[bLen-i]=='1')):((a[aLen-i]=='1')&&(b[bLen-i]=='1'));  //calc new carry bit
            a[aLen-i] = currBitSum?'1':'0';
        }
        
        if(carry){
            int i = aLen - bLen - 1;
            while(i>=0&&carry){
                carry = a[i]=='1';
                a[i] = (char)((a[i]!='1')+'0');
                i--;
            }
            if(carry){
                a = "1" + a;
            }
        }

        return a;
    }
};