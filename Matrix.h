#pragma once
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void MultiplyStandard(int size);
void MultiplyTransposed(int size);

template<typename MatrixType>
void Multiply(MatrixType& firstMatrix, MatrixType& secondMatrix, MatrixType& multiplyMatrix, int sizeMatrixs);
template<typename MatrixType>
void Transpose(MatrixType& secondMatrix, int sizeMatrixs);