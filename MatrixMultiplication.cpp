#include "Matrix.h"
#include <iostream>
using namespace std;


template<typename MatrixType>
void Multiply(MatrixType& firstMatrix, MatrixType& secondMatrix, MatrixType& multiplyMatrix, int sizeMatrixs)
{
    for (int i = 0; i < sizeMatrixs; i++)
    {
        for (int j = 0; j < sizeMatrixs; j++)
        {
            for (int k = 0; k < sizeMatrixs; k++)
            {
                multiplyMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Заменяем лямбду Transpose на шаблонную функцию
template<typename MatrixType>
void Transpose(MatrixType& secondMatrix, int sizeMatrixs)
{
    for (int i = 0; i < sizeMatrixs; i++)
    {
        for (int j = i; j < sizeMatrixs; j++)
        {
            int temp = (secondMatrix[i][j]);
            secondMatrix[i][j] = (secondMatrix[j][i]);
            secondMatrix[j][i] = (temp);
        }
    }
}


void MultiplyStandard(int size)
{
    vector<vector<int>> A(size, vector<int>(size));
    vector<vector<int>> B(size, vector<int>(size));
    vector<vector<int>> C(size, vector<int>(size, 0));
    srand(time(nullptr));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                C[i][j] += A[i][k] * B[k][j];
    auto end = chrono::high_resolution_clock::now();
    cout << "Время: " << chrono::duration<double>(end - start).count() << " сек\n";
}

void MultiplyTransposed(int size)
{
    vector<vector<int>> A(size, vector<int>(size));
    vector<vector<int>> B(size, vector<int>(size));
    vector<vector<int>> BT(size, vector<int>(size));
    vector<vector<int>> C(size, vector<int>(size, 0));
    srand(time(nullptr));
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            BT[j][i] = B[i][j];
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                C[i][j] += A[i][k] * BT[j][k];
    auto end = chrono::high_resolution_clock::now();
    cout << "Время: " << chrono::duration<double>(end - start).count() << " сек\n";
}
