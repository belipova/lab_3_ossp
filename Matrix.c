#include <stdlib.h>
#include <stdio.h>
#include "SMATRIX.h"

SVectorPtr VectorCreate(unsigned long int NumElement) {
    SVectorPtr v = *(SVector*)malloc(sizeof(SVector));
    v.VectorSize = NumElement;
    v.Data = calloc(NumElement, sizeof(double));
    return v;
}

void VectorDisplay(SVector v1) {
    printf("\nvector[%lu]:", v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++)
        printf(" %g", v1.Data[i]);
    printf("\n");
}

SVector VectorAdd(SVector v1, SVector v2) {
    if (v1.VectorSize != v2.VectorSize) {
        printf("Error: Vectors must have the same size for addition.\n");
        exit(1);
    }
    SVector result = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        result.Data[i] = v1.Data[i] + v2.Data[i];
    }
    return result;
}

SVector VectorDiff(SVector v1, SVector v2) {
    if (v1.VectorSize != v2.VectorSize) {
        printf("Error: Vectors must have the same size for subtraction.\n");
        exit(1);
    }
    SVector result = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        result.Data[i] = v1.Data[i] - v2.Data[i];
    }
    return result;
}

double VectorScalar(SVector v1, SVector v2) {
    if (v1.VectorSize != v2.VectorSize) {
        printf("Error: Vectors must have the same size for scalar product.\n");
        exit(1);
    }
    double result = 0.0;
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        result += v1.Data[i] * v2.Data[i];
    }
    return result;
}

SVector VectorMultConst(SVector v1, double c) {
    SVector result = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        result.Data[i] = v1.Data[i] * c;
    }
    return result;
}

SVector VectorCopy(SVector v1) {
    SVector result = VectorCreate(v1.VectorSize);
    for (unsigned long int i = 0; i < v1.VectorSize; i++) {
        result.Data[i] = v1.Data[i];
    }
    return result;
}

void VectorDelete(SVectorPtr v1) {
    free(v1.Data);
    free(&v1);
}

SMatrixPtr MatrixCreate(unsigned long int row, unsigned long int col) {
    SMatrixPtr m = *(SMatrix*)malloc(sizeof(SMatrix));
    m.Row = row;
    m.Col = col;
    m.Data = (double **)malloc(row * sizeof(double *));
    for (unsigned long int i = 0; i < row; i++) {
        m.Data[i] = (double *)calloc(col, sizeof(double));
    }
    return m;
}

void MatrixDisplay(SMatrix m1) {
    printf("\nMatrix[%lu][%lu]:\n", m1.Row, m1.Col);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            printf("%g\t", m1.Data[i][j]);
        }
        printf("\n");
    }
}

void MatrixMakeE(SMatrixPtr m1) {
    if (m1.Row != m1.Col) {
        printf("Error: Cannot make identity matrix for non-square matrix.\n");
        exit(1);
    }
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            m1.Data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

SMatrix MatrixMMMult(SMatrix m1, SMatrix m2) {
    if (m1.Col != m2.Row) {
        printf("Error: Matrix dimensions mismatch for matrix-matrix multiplication.\n");
        exit(1);
    }
    SMatrix result = MatrixCreate(m1.Row, m2.Col);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m2.Col; j++) {
            for (unsigned long int k = 0; k < m1.Col; k++) {
                result.Data[i][j] += m1.Data[i][k] * m2.Data[k][j];
            }
        }
    }
    return result;
}

SMatrix MatrixMMAdd(SMatrix m1, SMatrix m2) {
    if (m1.Row != m2.Row || m1.Col != m2.Col) {
        printf("Error: Matrix dimensions mismatch for matrix-matrix addition.\n");
        exit(1);
    }
    SMatrix result = MatrixCreate(m1.Row, m1.Col);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            result.Data[i][j] = m1.Data[i][j] + m2.Data[i][j];
        }
    }
    return result;
}

SMatrix MatrixMVMult(SMatrix m1, SVector v1) {
    if (m1.Col != v1.VectorSize) {
        printf("Error: Matrix and vector dimensions mismatch for matrix-vector multiplication.\n");
        exit(1);
    }
    SMatrix result = MatrixCreate(m1.Row, 1);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            result.Data[i][0] += m1.Data[i][j] * v1.Data[j];
        }
    }
    return result;
}

SMatrix MatrixCopy(SMatrix m1) {
    SMatrix result = MatrixCreate(m1.Row, m1.Col);
    for (unsigned long int i = 0; i < m1.Row; i++) {
        for (unsigned long int j = 0; j < m1.Col; j++) {
            result.Data[i][j] = m1.Data[i][j];
        }
    }
    return result;
}

void MatrixDelete(SMatrixPtr m1) {
    for (unsigned long int i = 0; i < m1.Row; i++) {
        free(m1.Data[i]);
    }
    free(m1.Data);
    free(&m1);
}
