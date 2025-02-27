#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>		//функции rand srand
#include <time.h>		//для рандомного числа
#include <cmath>

int index(int i, int j, int N);
void FillMatrixConstants(int* matrix, int N);
void FillMatrixRandom(int* matrix, int N);
void FillMatrixUser(int* matrix, int N);
void OutputMatrix(int* matrix, int N);