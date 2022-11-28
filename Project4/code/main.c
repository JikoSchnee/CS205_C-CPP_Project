#include <time.h>
#include <stdio.h>
#include <minwindef.h>
#include "matrix.h"
#pragma gcc optimize(3)

float * data16X16();
float * data128X128();
float * data1kX1k();
float * data8kX8k();
float * data10kX10k();
int main() {
    size_t size = 1000;
    matrix * a = NULL;

    float * data = data10kX10k();
    a = createMatrix(size,size,data);
    struct matrix * m1 = NULL;
//      m1 = strassen(a,a);
//    for (int i = 0; i < 100; ++i)
    m1 = matmul_improved(a,a);
    deleteMatrix(m1);
    struct timeb tb;
    ftime(&tb);
    long start_time= tb.time*1000+tb.millitm;
    m1 = matmul_improved(a,a);
//        m1 = strassen(a,a);
    ftime(&tb);
    long end_time= tb.time*1000+tb.millitm;
    double rs=end_time-start_time;
    printf("rs=%f\n",rs);
    return 0;
}