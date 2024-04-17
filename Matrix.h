#ifndef __MATRIX_H
#define __MATRIX_H
#include "SMatrix.h"

SVector VectorCreate(unsigned long int);
void VectorDisplay(SVector);
SVector VectorAdd(SVector, SVector);
SVector VectorDiff(SVector, SVector);
double VectorScalar(SVector, SVector);
SVector VectorMultConst(SVector, double);
SVector VectorCopy(SVector);
void VectorDelete(SVector *);
SMatrix MatrixCreate(unsigned long int, unsigned long int);
void MatrixDisplay(SMatrix);
void MatrixMakeE(SMatrix *);
SMatrix MatrixMMMult(SMatrix, SMatrix);
SMatrix MatrixMMAdd(SMatrix, SMatrix);
SMatrix MatrixMVMult(SMatrix, SVector);
SMatrix MatrixCopy(SMatrix);
void MatrixDelete(SMatrix *);
#endif