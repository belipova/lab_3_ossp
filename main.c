#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
int main()
{
    printf("\nStart!\n");
    SVector v1 = VectorCreate(2);
    v1.Data[0] = 1;

    SVector v2 = VectorCreate(2);
    v2.Data[0] = 2;

    VectorDisplay(v1);
    VectorDisplay(v2);

    VectorDisplay(VectorAdd(v1, v2));
    
    SMatrix m1 = MatrixCreate(2, 2);
    m1.Data[0][1] = 5;

    SMatrix m2 = MatrixCreate(2, 2);
    m2.Data[0][0] = 2;
    
    MatrixDisplay(m1);
    MatrixDisplay(m2);

    MatrixDisplay(MatrixMMAdd(m1, m2));
    
    printf("\nStoped!\n");



    return 0;
}

// gcc SMatrix.h Matrix.h Matrix.c main.c -o test