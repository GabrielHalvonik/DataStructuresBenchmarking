#pragma once

#include "Matrix/Matrix.h"
#include "RandomGenerator.h"

class MatrixOperations {
public:
	MatrixOperations() = delete;

	template <typename T>
	static void spristupni(Structures::Matrix<T>*);

	template <typename T>
	static void nastav(Structures::Matrix<T>*);

	template <typename T>
	static void vynasob(Structures::Matrix<T>*);
};

template<typename T>
void MatrixOperations::spristupni(Structures::Matrix<T>* matrix) {
	int row = RandomGenerator::randomIntBetween(0, matrix->getRows() - 1);
	int col = RandomGenerator::randomIntBetween(0, matrix->getColumns() - 1);
	(*matrix)[row][col];
}

template<typename T>
void MatrixOperations::nastav(Structures::Matrix<T>* matrix) {
	int row = RandomGenerator::randomIntBetween(0, matrix->getRows() - 1);
	int col = RandomGenerator::randomIntBetween(0, matrix->getColumns() - 1);
	(*matrix)[row][col] = row + col;
}

template<typename T>
void MatrixOperations::vynasob(Structures::Matrix<T>* matrix) {
	delete matrix->multiply(*matrix);
}
