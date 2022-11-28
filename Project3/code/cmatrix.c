#include <stdio.h>
#include <malloc.h>
#include "cmatrix.h"

bool printFalse(struct matrix *mat) {
    if (mat == NULL) {
        printf("mat pointer is NULL.\n");
    } else {
        if (mat->column <= 0) {
            printf("mat's column <= 0.\n");
        }
        if (mat->row <= 0) {
            printf("mat's row <= 0.\n");
        }
        if (mat->data == NULL) {
            printf("data of this mat is NULL.\n");
        }
    }
}


void refreshType(struct matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"refreshType\": input an invalid matrix.\n");
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
        for (int i = 0; i < mat->row; ++i) {
            for (int j = 0; j < mat->column; ++j) {
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
        for (int i = 0; i < mat->row; ++i) {
            for (int j = 0; j < i; ++j) {
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
    for (int i = 0; i < mat->row; ++i) {
        if (mat->data[i * mat->column + i] != 1) {
            mat->identical = 0;
            break;
        }
    }
}

void printMatrix(const struct matrix const *mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"printMatrix\": input an invalid matrix.\n");
        printFalse(mat);
        return;
    }
    if (mat->column * mat->row != 0) {
        printf("\n");
        int index = 0;
        for (int i = 0; i < mat->row; ++i) {
            for (int j = 0; j < mat->column; ++j) {
                printf("%3.f ", mat->data[index]);
                index++;
            }
            printf("\n");
        }
    } else {
        printf("Error in \"printMatrix\": input an invalid matrix.\n");
    }
    printf("\n");
    return;
}

struct matrix *createMatrix(const long r, const long c, float *data) {
    if (data == NULL) {
        printf("Error in \"createMatrix\": Pointer is NULL.\n");
        return NULL;
    } else if (r * c == 0 || data == NULL) {
        printf("Error in \"createMatrix\": Matrix is empty.\n");
        return NULL;
    }
    struct matrix *newMat = (struct matrix *) malloc(1);
    newMat->row = r;
    newMat->column = c;
    float *saveData;
    saveData = (float *) malloc(r * c * sizeof(float));
    for (int i = 0; i < r * c; ++i) {
        saveData[i] = data[i];
    }
    newMat->data = saveData;
    refreshType(newMat);
    return newMat;
}

void deleteMatrix(struct matrix **mat_loc) {
    if (mat_loc == NULL||*mat_loc == NULL) {
        printf("Error in \"deleteMatrix\": this mat is NULL.\n");
        return;
    }
    free((*mat_loc)->data);
    (*mat_loc)->data = NULL;
    free(*mat_loc);
    *mat_loc = NULL;
}

struct matrix *copyMatrix(const struct matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"copyMatrix\": input an invalid matrix.\n");
        printFalse(mat);
        return NULL;
    }
    float array[mat->row * mat->column];
    for (int i = 0; i < mat->row * mat->column; ++i) {
        array[i] = mat->data[i];
    }
    return createMatrix(mat->row, mat->column, array);
}

struct matrix *addMatrix(const struct matrix *const mat1, const struct matrix *const mat2) {
    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
        printf("Error in \"addMatrix\": input an invalid matrix(left).\n");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
        printf("Error in \"addMatrix\": input an invalid matrix(right).\n");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->column || mat1->row != mat2->row) {
        printf("Error in \"addMatrix\": matrix1 %d columns, matrix1 %d rows\n", mat1->column, mat1->row);
        printf("                      matrix2 %d columns, matrix2 %d rows\n", mat2->column, mat2->row);
        return NULL;
    }
    int c = mat1->column;
    int r = mat1->row;
    float array[c * r];
    for (int i = 0; i < c * r; ++i) {
        array[i] = mat1->data[i] + mat2->data[i];
    }
    return createMatrix(r, c, array);
}

struct matrix *subMatrix(const struct matrix *const mat1, const struct matrix *const mat2) {
    if (mat1 == NULL || mat1->column <= 0 || mat1->row <= 0 || mat1->data == NULL) {
        printf("Error in \"subMatrix\": input an invalid matrix(left).\n");
        printFalse(mat1);
        return NULL;
    } else if (mat2 == NULL || mat2->column <= 0 || mat2->row <= 0 || mat2->data == NULL) {
        printf("Error in \"subMatrix\": input an invalid matrix(right).\n");
        printFalse(mat2);
        return NULL;
    } else if (mat1->column != mat2->column || mat1->row != mat2->row) {
        printf("Error in \"subMatrix\": matrix1 %d columns, matrix1 %d rows\n", mat1->column, mat1->row);
        printf("Error in \"subMatrix\": matrix2 %d columns, matrix2 %d rows\n", mat2->column, mat2->row);
        return NULL;
    }
    int c = mat1->column;
    int r = mat1->row;
    float array[c * r];
    for (int i = 0; i < c * r; ++i) {
        array[i] = mat1->data[i] - mat2->data[i];
    }
    return createMatrix(r, c, array);
}

void mulScalar(struct matrix *const mat, float scalar) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"mulScalar\": Input an invalid matrix");
        printFalse(mat);
        return;
    }
    long r = mat->row;
    long c = mat->column;
    for (int i = 0; i < c * r; ++i) {
        mat->data[i] = mat->data[i] * scalar;
    }
    return;
}

struct matrix *mulMatrix(const struct matrix *const mat1, const struct matrix *const mat2) {
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
    float array[r * c];
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

struct matrix *transportMatrix(const struct matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"transportMatrix\": Invalid input.");
        printFalse(mat);
        return NULL;
    }
    long r = mat->column;
    long c = mat->row;
    long index = 0;
    float array[r * c];
    for (int i = 0; i < mat->column; ++i) {
        for (int j = 0; j < mat->row; ++j) {
            array[index++] = mat->data[i + j * mat->column];
        }
    }
    struct matrix *newMatrix = createMatrix(r, c, array);
    return newMatrix;
}

void addScalar(struct matrix *const mat, float scalar) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"addSac\": Invalid input.");
        printFalse(mat);
        return;
    }
    for (int i = 0; i < mat->column * mat->row; ++i) {
        mat->data[i] += scalar;
    }
}

void subScalar(struct matrix *const mat, float scalar) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"subSac\": Invalid input.");
        printFalse(mat);
        return;
    }
    for (int i = 0; i < mat->column * mat->row; ++i) {
        mat->data[i] -= scalar;
    }
}

float findMin(const struct matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"findMin\": ");
        printFalse(mat);
        return 0.0f;
    }
    float min = mat->data[0];
    for (int i = 0; i < mat->row * mat->column; ++i) {
        if (mat->data[i] < min) {
            min = mat->data[i];
        }
    }
    return min;
}

float findMax(const struct matrix *const mat) {
    if (mat == NULL || mat->column <= 0 || mat->row <= 0 || mat->data == NULL) {
        printf("Error in \"findMax\": ");
        printFalse(mat);
        return 0.0f;
    }
    float max = mat->data[0];
    for (int i = 0; i < mat->row * mat->column; ++i) {
        if (mat->data[i] > max) {
            max = mat->data[i];
        }
    }
    return max;
}

















