#ifndef CALCULATOR_STRUCT_DIVIDE_INTERNET_H
#define CALCULATOR_STRUCT_DIVIDE_INTERNET_H
#include <cstring>

class divide_internet {};
typedef struct bigNum{
    int data[10000];
    int len;
    int p;      //是否是非负数
    bigNum(){
        memset(data, 0, sizeof(data));
        len = 0;
        p = 1;
    }
}bn;
bn bigDivide(bn a, bn b);

#endif //CALCULATOR_STRUCT_DIVIDE_INTERNET_H
