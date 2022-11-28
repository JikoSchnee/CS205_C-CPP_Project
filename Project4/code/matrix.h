#ifndef MATRIX_ULTRA_MATRIX_H
#define MATRIX_ULTRA_MATRIX_H

#include <stdbool.h>
#include <corecrt.h>

typedef struct matrix{
    //basic info
    size_t row;
    size_t column;
    float * data;
    //addition info
    bool square;      //方阵
    bool diagnose;    //对角矩阵
    bool symmetric;   //对称矩阵
    bool identical;   //单位矩阵
}matrix;

void printMatrix(matrix * mat);

struct matrix * createMatrix(size_t r,size_t c,float * data);                    //一维数组导入法
bool deleteMatrix(matrix * mat);                                                 //删除矩阵
void refreshType(matrix * mat);                                                  //类型更新
matrix * addMatrix(const matrix * mat1,const matrix * mat2);                     //两个矩阵相加，返回盛放结果矩阵的地址
matrix * subMatrix(const matrix * mat1,const matrix * mat2);                     //两个矩阵相减，前减后，返回盛放结果矩阵的地址
matrix * transportMatrix(const matrix * mat);                                    //矩阵转置
matrix * matmul_plain(const matrix * mat1, const matrix * mat2);                 //暴力乘法
matrix * matmul_improved(const matrix * mat1, const matrix * mat2);              //改进乘法

matrix *matmul_avx(const matrix *mat1, const matrix *mat2);                      //avx
matrix *strassen(const matrix *mat1, const matrix *mat2);                        //strassen

#endif //MATRIX_ULTRA_MATRIX_H
