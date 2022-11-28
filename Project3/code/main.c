#include <stdio.h>
#include "cmatrix.h"
float one[1] = {1};
int main() {
    float case1_data[6] = {1.f, 0.f, 0.f, 2.f, 2.f, 3.f};
//    float case2_data[6] = {1.f, 0.f, 5.f, 7.f, 7.f, 0.f};
    struct matrix *case1 = createMatrix(3, 2, case1_data);
//    struct matrix *case2 = createMatrix(2, 3, case2_data);
//    printf("case1");
    printMatrix(case1);
//    printf("case2");
//    printMatrix(case2);
//
//    printf("S1\nbegin\n");
//    printf("case1 plus case1");
//    printMatrix(addMatrix(case1, case1));
//    printf("end\n");
//
//    printf("S2\nbegin\n");
//    printf("case1 subtract case2");
//    printMatrix(subMatrix(case1, case2));
//    printf("end\n");
//
//    printf("S1\nbegin\n");
//    printf("case1 plus case1");
//    printMatrix(addMatrix(case1, case1));
//    printf("end\n");
//
//    printf("S3\nbegin\n");
//    printf("case1 multiply case2");
//    printMatrix(mulMatrix(case1, case2));
//    printf("end\n");
//    printMatrix(mulMatrix(case2, transportMatrix(case2)));
//
//    struct matrix *case3 = createMatrix(2, 3, case2_data);
//    struct matrix *case4 = createMatrix(2, 3, case2_data);
//    struct matrix *case5 = createMatrix(2, 3, case2_data);
//    struct matrix *case6 = createMatrix(2, 3, case2_data);
    deleteMatrix(&case1);
//    puts("success");
    return 0;
}
