#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>		//������� rand srand
#include <time.h>		//��� ���������� �����
#include <cmath>

int index(int i, int j, int N);
void FillMatrixConstants(double* matrix, int N);
void FillMatrixConstants(double** matrix, int N);
void FillMatrixRandom(double* matrix, int N);
void FillMatrixRandom(double** matrix, int N);
void FillMatrixUser(double* matrix, int N);
void FillMatrixUser(double** matrix, int N);
void OutputMatrix(double* matrix, int N);
void OutputMatrix(double** matrix, int N);
void RaiseDegree(double* matrix, double* result, int N, int degree);
void RaiseDegree(double** matrix, double** result, int N, int degree);
