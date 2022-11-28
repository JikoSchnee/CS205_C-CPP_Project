#ifndef CALCULATOR_STRUCT_OPERATOR_H
#define CALCULATOR_STRUCT_OPERATOR_H
#include "numberSaver.h"

class Operator {};
struct number plu(number n1,number n2);             //加
struct number sub(number n1,number n2);             //减
struct number mul(number n1,number n2);             //乘
struct number div(number n1,number n2);             //除
struct number exp(number n1,int times);             //指数
struct number tenTimes(int times);                  //10^n

#endif //CALCULATOR_STRUCT_OPERATOR_H
