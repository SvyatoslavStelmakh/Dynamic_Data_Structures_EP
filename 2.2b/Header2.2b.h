#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>		//������� rand srand
#include <time.h>		//��� ���������� �����
#include <cmath>

int index(int i, int j, int N);
void FillMatrixConstants(int* matrix, int N);
void FillMatrixRandom(int* matrix, int N);
void FillMatrixUser(int* matrix, int N);
void OutputMatrix(int* matrix, int N);