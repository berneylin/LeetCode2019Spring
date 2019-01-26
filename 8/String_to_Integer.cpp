#include<cstring>
#include<climits>
#include<cstdio>

int myAtoi(char* str) {
    long ret = 0; // return number
    int len = strlen(str);
    int s = 0;  // start_index
    int flag = 1;  // postive return number by default
    int is_first = 1;
    
    // find the start index
    for(int i=0;i<len;i++){
        if(str[i]==' ') continue;
        else {
            if(str[i]=='-'||str[i]=='+'||(str[i]>='0'&&str[i]<='9')){
                s = i;
                break;
            }else return 0;
        }
    }

    // symbol handle
    if(str[s]=='-'){
        flag = 0;  // negative number
        s++;
    }else if(str[s]=='+'){
        s++;
    }


    for(int i=s;i<len && (str[i]>='0'&&str[i]<='9');i++){
        if(is_first){
            is_first = 0;
        }
        else{
            ret *= 10;
        }

        if(flag){
            ret += (str[i]-'0');
            if(ret>INT_MAX || ret<0) {
                return INT_MAX;
            }
        }else{
            ret -= (str[i]-'0');
            if(ret<INT_MIN || ret>0){
                return INT_MIN;
            }
        }
    }
    
    return ret;
}

int main(void){
    char tmp[1000];
    scanf("%s", tmp);

    printf("%d", myAtoi(tmp));

    return 0;
}
