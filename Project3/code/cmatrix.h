#ifndef MATRIX_CMATRIX_H
#define MATRIX_CMATRIX_H

#include <stdbool.h>

struct matrix{
    //basic info
    long row;
    long column;
    float * data;
    //addition info
    bool square;      //方阵
    bool diagnose;    //对角矩阵
    bool symmetric;   //对称矩阵
    bool identical;   //单位矩阵
};

bool printFalse(struct matrix *mat);
void ptUD(int times,int UorD);
void printMatrix(const struct matrix * mat);                                                          //打印矩阵
void refreshType(struct matrix * const mat);                                                          //更新矩阵额外信息

struct matrix * createMatrix(const long r,const long c,float * data);                                 //一维数组导入法
struct matrix * copyMatrix(const struct matrix * const mat);                                          //返回一个一样的矩阵的地址
struct matrix * addMatrix(const struct matrix * const mat1,const struct matrix * const mat2);         //两个矩阵相加，返回盛放结果矩阵的地址
struct matrix * subMatrix(const struct matrix * const mat1,const struct matrix * const mat2);         //两个矩阵相减，前减后，返回盛放结果矩阵的地址
struct matrix * mulMatrix(const struct matrix * const mat1,const struct matrix * const mat2);         //两个矩阵相乘
struct matrix * transportMatrix(const struct matrix * const mat);                                     //返回盛放转置后结果的矩阵的地址
void deleteMatrix(struct matrix ** mat);                                                              //删除矩阵
void mulScalar(struct matrix * const mat, float scalar);                                              //矩阵乘常数，返回盛放结果矩阵的地址
void addScalar(struct matrix * const mat, float scalar);                                              //矩阵加上一个数，直接在原地址上改变
void subScalar(struct matrix * const mat, float scalar);                                              //矩阵减去一个数，直接在原地址上改变
float findMin(const struct matrix * const mat);                                                       //找到矩阵中最小的数字
float findMax(const struct matrix * const mat);                                                       //找到矩阵中最大的数字



#endif //MATRIX_CMATRIX_H
