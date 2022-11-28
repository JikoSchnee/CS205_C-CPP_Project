#include "matrix.h"
#include <stdio.h>
#include <malloc.h>
//#include <immintrin.h>

#pragma gcc optimize(3)

void printFalse(const matrix *mat) {
    if (mat == NULL) {
        fprintf(stderr, "mat pointer is NULL.\n");
    } else {
        if (mat->column <= 0) {
            fprintf(stderr, "mat's column <= 0.\n");
        }
        if (mat->row <= 0) {
            fprintf(stderr, "mat's row <= 0.\n");
        }
        if (mat->data == NULL) {
            fprintf(stderr, "data of this mat is NULL.\n");
        }
    }
}

void printMatrix(matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        fprintf(stderr, "Error in \"printMatrix\": input an invalid matrix.\n");
        printFalse(mat);
        return;
    }
    if (mat->column * mat->row != 0) {
        fprintf(stderr, "\n");
        int index = 0;
        for (int i = 0; i < mat->row; ++i) {
            for (int j = 0; j < mat->column; ++j) {
                fprintf(stderr, "%3.f ", mat->data[index]);
                index++;
            }
            fprintf(stderr, "\n");
        }
    } else {
        fprintf(stderr, "Error in \"printMatrix\": input an invalid matrix.\n");
    }
    fprintf(stderr, "\n");
}

matrix *createMatrix(const size_t r, const size_t c, float *data) {
    if (data == NULL) {
        fprintf(stderr, "Error in \"createMatrix\": Pointer is NULL.\n");
        return NULL;
    } else if (r * c == 0 || data == NULL) {
        fprintf(stderr, "Error in \"createMatrix\": Matrix is empty.\n");
        return NULL;
    }
    matrix *newMat = NULL;
    newMat = (matrix *) malloc(sizeof(matrix));
    if (newMat == NULL) {
        fprintf(stderr, "Error in \"createMatrix\": Fail to malloc space for mat pointer.\n");
        return NULL;
    }
    newMat->row = r;
    newMat->column = c;
    float *saveData = NULL;
    saveData = (float *) malloc(r * c * sizeof(float));
    if (saveData == NULL) {
        fprintf(stderr, "Error in \"createMatrix\": Fail to malloc space for data pointer.\n");
        free(newMat);
        return NULL;
    }

    for (size_t i = 0; i < r * c; ++i)saveData[i] = data[i];
    newMat->data = saveData;
//    refreshType(newMat);
    return newMat;
}

bool deleteMatrix(matrix *mat) {
    if (!mat)return false;
    if (mat->data) {
        free(mat->data);
    }
    free(mat);
    return true;
}

void refreshType(matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        fprintf(stderr, "Error in \"refreshType\": input an invalid matrix.\n");
        return;
    }
    //方阵
    if (mat->column == mat->row) {
        mat->square = 1;
    } else {
        mat->square = 0;
    }
    //对称
    if (mat->column == mat->row) {
        mat->symmetric = 1;
        for (size_t i = 0; i < mat->row; ++i) {
            for (size_t j = 0; j < mat->column; ++j) {
                if (mat->data[i * mat->column + j] != mat->data[i + j * mat->row]) {
                    mat->symmetric = 0;
                }
            }
            if (mat->symmetric == 0) {
                break;
            }
        }
    } else {
        mat->symmetric = 0;
    }
    //对角
    if (mat->symmetric) {
        mat->diagnose = 1;
        for (size_t i = 0; i < mat->row; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (mat->data[i * mat->column + j] != 0) {
                    mat->diagnose = 0;
                    break;
                }
            }
            if (mat->diagnose == 0) {
                break;
            }
        }
    } else {
        mat->diagnose = 0;
    }
    //单位
    mat->identical = 1;
    for (size_t i = 0; i < mat->row; ++i) {
        if (mat->data[i * mat->column + i] != 1) {
            mat->identical = 0;
            break;
        }
    }
}

matrix *addMatrix(const matrix *const mat1, const matrix *const mat2) {
    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
        fprintf(stderr, "Error in \"addMatrix\": input an invalid matrix(left).\n");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
        fprintf(stderr, "Error in \"addMatrix\": input an invalid matrix(right).\n");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->column || mat1->row != mat2->row) {
        fprintf(stderr, "Error in \"addMatrix\": matrix1 %d columns, matrix1 %d rows\n", mat1->column, mat1->row);
        fprintf(stderr, "                      matrix2 %d columns, matrix2 %d rows\n", mat2->column, mat2->row);
        return NULL;
    }
    size_t c = mat1->column;
    size_t r = mat1->row;
    float array[c * r];
    for (size_t i = 0; i < c * r; ++i) {
        array[i] = mat1->data[i] + mat2->data[i];
    }
    return createMatrix(r, c, array);
}

matrix *subMatrix(const matrix *const mat1, const matrix *const mat2) {
    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
        fprintf(stderr, "Error in \"subMatrix\": input an invalid matrix(left).\n");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
        fprintf(stderr, "Error in \"subMatrix\": input an invalid matrix(right).\n");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->column || mat1->row != mat2->row) {
        fprintf(stderr, "Error in \"subMatrix\": matrix1 %d columns, matrix1 %d rows\n", mat1->column, mat1->row);
        fprintf(stderr, "Error in \"subMatrix\": matrix2 %d columns, matrix2 %d rows\n", mat2->column, mat2->row);
        return NULL;
    }
    size_t c = mat1->column;
    size_t r = mat1->row;
    float array[c * r];
    for (size_t i = 0; i < c * r; ++i) {
        array[i] = mat1->data[i] - mat2->data[i];
    }
    return createMatrix(r, c, array);
}

struct matrix *transportMatrix(const struct matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"transportMatrix\": Invalid input.");
        printFalse(mat);
        return NULL;
    }
    long r = mat->column;
    long c = mat->row;
    long index = 0;
    float * array = NULL;
    array = malloc(r*c*sizeof (float ));
    if(!array){
        fprintf(stderr,"Error in \"transportMatrix\": Fail to malloc space.");
        return NULL;
    }
    for (int i = 0; i < mat->column; ++i) {
        for (int j = 0; j < mat->row; ++j) {
            array[index++] = mat->data[i + j * mat->column];
        }
    }
    struct matrix *newMatrix = createMatrix(r, c, array);
    return newMatrix;
}
matrix *matmul_plain(const matrix *const mat1, const matrix *const mat2) {
    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
        printf("Error in \"mulMatrix\": Input a invalid matrix(left)");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
        printf("Error in \"mulMatrix\": Input a invalid matrix(right)");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->row) {
        printf("Error in \"mulMatrix\": mat1's column(%d) not equal mat2's row(%d).\n", mat1->column, mat2->row);
        return NULL;
    }
    long r = mat1->row;
    long c = mat2->column;
    float * array = NULL;
    array = malloc(r*c*sizeof (float ));
    if (!array){
        printf("Error in \"mulMatrix\": Fail to malloc space.\n");
        return NULL;
    }
    long indexResult = 0;
    for (int i = 0; i < mat1->row; ++i) {
        for (int j = 0; j < mat2->column; ++j) {
            array[indexResult] = 0;
            for (int k = 0; k < mat1->column; ++k) {
                array[indexResult] += mat1->data[i * mat1->column + k] * mat2->data[j + mat2->column * k];
            }
            indexResult++;
        }
    }
    struct matrix *newMatrix = createMatrix(r, c, array);
    return newMatrix;
}

matrix *matmul_improved(const matrix *mat1, const matrix *mat2) {
    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
        fprintf(stderr, "Error in \"mulMatrix\": Input a invalid matrix(left)");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
        fprintf(stderr, "Error in \"mulMatrix\": Input a invalid matrix(right)");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->row) {
        fprintf(stderr, "Error in \"mulMatrix\": mat1's column(%d) not equal mat2's row(%d).\n", mat1->column,
                mat2->row);
        return NULL;
    }
    size_t r = mat1->row;
    size_t c = mat2->column;
    float *array = NULL;
    array = malloc(r * c * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Error in \"mulMatrix\": Fail to malloc space for data.\n", mat1->column, mat2->row);
        return NULL;
    }
    float tem = 0;
#pragma omp parallel for num_threads(16)
    for (int i = 0; i < r; ++i)
        for (int k = 0; k < r; ++k) {
            tem = mat1->data[i * r + k];
            for (int j = 0; j < r; ++j) {
                array[i * r + j] += tem * mat2->data[k * r + j];
            }
        }
    matrix *newMatrix = createMatrix(r, c, array);
    return newMatrix;
}

//matrix *matmul_avx(const matrix *mat1, const matrix *mat2){
//    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
//        fprintf(stderr, "Error in \"mulMatrix\": Input a invalid matrix(left)");
//        printFalse(mat1);
//        return NULL;
//    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
//        fprintf(stderr, "Error in \"mulMatrix\": Input a invalid matrix(right)");
//        printFalse(mat2);
//        return NULL;
//    } else if (mat1->column != mat2->row) {
//        fprintf(stderr, "Error in \"mulMatrix\": mat1's column(%d) not equal mat2's row(%d).\n", mat1->column,
//                mat2->row);
//        return NULL;
//    }
//    size_t r = mat1->row;
//    size_t c = mat2->column;
//    float *array = NULL;
//    array = malloc(r * c * sizeof(float));
//    if (array == NULL) {
//        fprintf(stderr, "Error in \"mulMatrix\": Fail to malloc space for data.\n", mat1->column, mat2->row);
//        return NULL;
//    }
//    matrix * mat3 = transportMatrix(mat2);
//
//    for (int i = 0; i < r * c; ++i) {
//        array[i] = 0;
//    }
//    float * tem= NULL;
//    tem = malloc(8*sizeof (int ));
//    __m256 load1 = _mm256_setzero_ps();
//    __m256 load2 = _mm256_setzero_ps();
//    __m256 sum = _mm256_setzero_ps();
//    size_t index = 0;
//    size_t row = 0;
//    size_t i = 0,j = 0;
//    while (i<mat1->row) {
//#pragma omp parallel for
//        for (int k = 0; k < mat1->column; k+=8) {
//            load1 = _mm256_loadu_ps(&mat1->data[i*mat1->column+k]);
//            load2 = _mm256_loadu_ps(&mat3->data[j*mat3->column+k]);
//            sum = _mm256_mul_ps(load1,load2);
//            _mm256_storeu_ps(tem, sum);
//            for (int l = 0; l < 8; ++l) {
//                array[i*c+j] += tem[i];
//            }
//        }
//        j++;
//        if (j>=mat3->row){
//            j = 0;
//            i++;
//        }
//    }
//    matrix *newMatrix = createMatrix(r, c, array);
//    return newMatrix;
//}

matrix *strassen(const matrix *mat1, const matrix *mat2) { //需要变成偶数阶方阵
    if (mat1->row != mat2->column)return matmul_improved(mat1, mat2);
    size_t row1 = mat1->row;
    size_t row2 = mat2->row;
    size_t column1 = mat1->column;
    size_t column2 = mat2->column;
    //若不为偶数阶矩阵则用常规乘法
    if (row1 % 2 != 0 || column1 % 2 != 0)return matmul_improved(mat1, mat2);
    if (mat1->column <= 64)return matmul_improved(mat1, mat2);
    size_t newSize = mat1->row / 2;
    size_t rXc = row1 * column2;
    float *data1 = mat1->data;
    float *data2 = mat2->data;
    float *a11 = malloc(rXc * sizeof(float));
    float *a12 = malloc(rXc * sizeof(float));
    float *a21 = malloc(rXc * sizeof(float));
    float *a22 = malloc(rXc * sizeof(float));
    float *b11 = malloc(rXc * sizeof(float));
    float *b12 = malloc(rXc * sizeof(float));
    float *b21 = malloc(rXc * sizeof(float));
    float *b22 = malloc(rXc * sizeof(float));
    matrix *c11 = NULL;
    matrix *c12 = NULL;
    matrix *c21 = NULL;
    matrix *c22 = NULL;

    matrix *m1 = NULL;
    matrix *m2 = NULL;
    matrix *m3 = NULL;
    matrix *m4 = NULL;
    matrix *m5 = NULL;
    matrix *m6 = NULL;
    matrix *m7 = NULL;


    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            a11[i * newSize + j] = data1[i * newSize + j];
            a12[i * newSize + j] = data1[i * newSize + j + newSize];
            a21[i * newSize + j] = data1[(i + newSize) * newSize + j];
            a22[i * newSize + j] = data1[(i + newSize) * newSize + j + newSize];
            b11[i * newSize + j] = data2[i * newSize + j];
            b12[i * newSize + j] = data2[i * newSize + j + newSize];
            b21[i * newSize + j] = data2[(i + newSize) * newSize + j];
            b22[i * newSize + j] = data2[(i + newSize) * newSize + j + newSize];
        }
    }
    matrix *A11 = createMatrix(newSize, newSize, a11);
    free(a11);
    matrix *A12 = createMatrix(newSize, newSize, a12);
    free(a12);
    matrix *A21 = createMatrix(newSize, newSize, a21);
    free(a21);
    matrix *A22 = createMatrix(newSize, newSize, a22);
    free(a22);
    matrix *B11 = createMatrix(newSize, newSize, b11);
    free(b11);
    matrix *B12 = createMatrix(newSize, newSize, b12);
    free(b12);
    matrix *B21 = createMatrix(newSize, newSize, b21);
    free(b21);
    matrix *B22 = createMatrix(newSize, newSize, b22);
    free(b22);

    matrix *tem1 = NULL, *tem2 = NULL;

    tem1 = addMatrix(A11, A22);
    tem2 = addMatrix(B11, B22);
    m1 = strassen(tem1, tem2);
    deleteMatrix(tem1);
    deleteMatrix(tem2);

    tem1 = addMatrix(A21, A22);
    m2 = strassen(tem1, B11);
    deleteMatrix(tem1);

    tem1 = subMatrix(B12, B22);
    m3 = strassen(tem1, A11);
    deleteMatrix(tem1);

    tem1 = subMatrix(B21, B11);
    m4 = strassen(tem1, A22);
    deleteMatrix(tem1);

    tem1 = addMatrix(A11, A12);
    m5 = strassen(tem1, B22);
    deleteMatrix(tem1);

    tem1 = subMatrix(A21, A11);
    tem2 = subMatrix(B11, B12);
    m6 = strassen(tem1, tem2);
    deleteMatrix(tem1);
    deleteMatrix(tem2);

    tem1 = subMatrix(A12, A22);
    tem2 = addMatrix(B21, B22);
    m7 = strassen(tem1, tem2);
    deleteMatrix(tem1);
    deleteMatrix(tem2);

    deleteMatrix(A11);
    deleteMatrix(A12);
    deleteMatrix(A21);
    deleteMatrix(A22);
    deleteMatrix(B11);
    deleteMatrix(B12);
    deleteMatrix(B21);
    deleteMatrix(B22);
    c11 = addMatrix(addMatrix(m1, m4), subMatrix(m7, m5));
    c12 = addMatrix(m3, m5);
    c21 = addMatrix(m2, m4);
    c22 = addMatrix(addMatrix(m1, m3), subMatrix(m6, m2));
    deleteMatrix(m1);
    deleteMatrix(m2);
    deleteMatrix(m3);
    deleteMatrix(m4);
    deleteMatrix(m5);
    deleteMatrix(m6);
    deleteMatrix(m7);
    float *resultData = malloc(rXc * sizeof(float));
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            resultData[i * newSize + j] = c11->data[i * newSize + j];
            resultData[i * newSize + j + newSize] = c12->data[i * newSize + j];
            resultData[(i + newSize) * newSize + j] = c21->data[i * newSize + j];
            resultData[(i + newSize) * newSize + j + newSize] = c22->data[i * newSize + j];
        }
    }
    matrix *result = createMatrix(mat1->row, mat2->column, resultData);
    deleteMatrix(c11);
    deleteMatrix(c12);
    deleteMatrix(c21);
    deleteMatrix(c22);
    free(resultData);
    return result;
}


