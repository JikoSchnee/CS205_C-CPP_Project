#include "numberSaver.h"

using namespace std;

struct number charToNum(char* key, int first, int last){
    struct number newNumber;
    int len = 0;
    for (int i = last,j = 0; i >= first; i--) {
        char tem = key[i];
        if (tem>='0'&&tem<='9'){
            newNumber.num[j++] = tem-'0';
            len++;
        } else if(tem == '.'){
            newNumber.pLoc = j-1;
        } else if(tem == '-'){
            newNumber.zf = -1;
        }
    }
    newNumber.len = len;
    return newNumber;
}
struct number cutZero(number key){
    while (key.num[key.len-1] == 0&&key.len-2>key.pLoc){//去掉头部的0
        key.len--;
    }
    int zeroCounter = 0;//去掉尾部的0
    int originLen = key.len;
    int ploc_tem = key.pLoc;
    for (int i = 0; i < key.pLoc+1; ++i) {
        if (key.num[i] == 0){
            key.len--;
            ploc_tem--;
            zeroCounter++;
        }else{
            break;
        }
    }
    key.pLoc = ploc_tem;
    for (int i = zeroCounter,j=0; i < originLen; ++i) {
        key.num[j++] = key.num[i];
    }
    return key;
}
int integerBit(number n){
    return n.len-n.pLoc-1;
}
int decimalBit(number n){
    return n.pLoc+1;
}
int compareNoZf(number n1,number n2){
    if(integerBit(n1)> integerBit(n2)){
        return 1;
    }else if (integerBit(n1)< integerBit(n2)){
        return -1;
    }else{
        for (int i = n1.len-1,j = n2.len-1; (i >= 0)&&(j >= 0); i--,j--) {
            if (n1.num[i]>n2.num[j]){
                return 1;
            }else if(n1.num[i]<n2.num[j]){
                return -1;
            }
            if (i==0&&j>0){
                return -1;
            }else if(j==0&&i>0){
                return 1;
            }else if(i==0&&j==0){
                return 0;
            }
        }
    }
}