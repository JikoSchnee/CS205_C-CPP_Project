#include <string>
#include "cstring"
#ifndef CALCULATOR_STRUCT_NUMBERSAVER_H
#define CALCULATOR_STRUCT_NUMBERSAVER_H

using namespace std;

class numberSaver {};
struct number{
    int num[1000];
    int len;
    int pLoc;
    int zf;
    int value;
    number(){
        memset(num, 0, sizeof(num));
        len = 0;
        zf = 1;
        pLoc = -1;
        value = 0;
    }
    number(int i){
        memset(num, 0, sizeof(num));
        if(i ==0){
            len = 1;
            zf = 1;
            pLoc = -1;
        }else{
            len = 0;
            zf = 1;
            pLoc = -1;
        }
    }
    int getValue(){
        char temChar[len+pLoc+1];
        int index = 0;
        if (zf == -1){
            temChar[index++] = '-';
        }
        for (int i = len-1; i >=0; --i) {
            temChar[index++] = num[i]+'0';
        }
        string str = temChar;
        return stoi(str);
    }
};
struct number charToNum(char* key, int first, int last);            //把char数组转成number类型
struct number cutZero(number key);                                  //清除前后没有意义的0
int integerBit(number n);                                           //返回该数整数位的个数
int decimalBit(number n);                                           //返回该数小数位的个数
int compareNoZf(number n1,number n2);                               //判断两数的大小，不考虑小数点后，用于减法

#endif //CALCULATOR_STRUCT_NUMBERSAVER_H
