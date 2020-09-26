#include <complex.h>
#include "matrix.h"

using namespace std;

template <typename T>
Matrix<T>* inputMatrix(T type)
{
	Matrix<T> *matrix;

	int rows = -1;
	int columns = -1;

	while(true)
	{
		std::cout << "rows: ";
		std::cin >> rows;
		if(rows > 0) break;
		std::cout << "rows must be positive\n";
	}

	while(true)
	{
		std::cout << "columns: ";
		std::cin >> columns;
		if(columns > 0) break;
		std::cout << "columns must be positive\n";
	}

	matrix = new Matrix<T>(rows, columns);

	std::cout << "elements of matrix:\n";
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < rows; j++)
		{
			T in;
			std::cin >> in;
			matrix->set(in, i, j);
		}
	}
	return matrix;
}

template <typename T>
void printMatrix(Matrix<T> *matrix){
	for(int i = 0; i < matrix->getRows(); i++)
	{
		for(int j = 0; j < matrix->getColumns(); j++)
		{
			std::cout << matrix->get(i, j) << " ";
		}
		std::cout << "\n";
	}
}

template <typename T>
void printSum(Matrix<T> *A, Matrix<T> *B)
{
	if(A == nullptr || B == nullptr)
	{
			std::cout << "A or B isn't set\n";
			return;
	}

	Matrix<T> *R = *A + *B;
	printMatrix(R);
	delete R;
}
template <typename T>
void printMatrixMul(Matrix<T> *A, Matrix<T> *B)
{
	if(A == nullptr || B == nullptr)
	{
			std::cout << "A or B isn't set\n";
			return;
	}
	Matrix<T> *R = *A * *B;
	printMatrix(R);
	delete R;
}


template <typename T>
void printMul(Matrix<T> *A, T c){
	if(A == nullptr){
		std::cout << "A isn't set\n";
		return;
	}
	printMatrix(A->scalarMult(c));
}

template <typename T>
void printNorm(Matrix<T> *A){
	if(A == nullptr){
		std::cout << "A isn't set\n";
		return;
	}
	std::cout << A->getNorm() << "\n";
}

void printMenu(){
	std::cout << "1. set A\n";
	std::cout << "2. set B\n";
	std::cout << "3. set c\n";
	std::cout << "4. get A+B\n";
	std::cout << "5. get B+A\n";
	std::cout << "6. get c*A\n";
	std::cout << "7. get A*B\n";
	std::cout << "8. get B*A\n";
	std::cout << "9. get norm of A\n";
	std::cout << "10. get norm of B\n";
	std::cout << "11. exit\n\n";
	std::cout << "choose: ";
}

template <typename T>
void interface(T type){
	Matrix<T> *A = nullptr;
	Matrix<T> *B = nullptr;
	T c = 0;

	while(true){
		printMenu();

		int choose = 0;
		std::cin >> choose;

		switch(choose){
			case 1:
				if(A) delete A;
				A = inputMatrix(type);
				break;
			case 2:
				if(B) delete B;
				B = inputMatrix(type);
				break;
			case 3:
				std::cout << "c: ";
				std::cin >> c;
				break;
			case 4:
				printSum(A, B);
				break;
			case 5:
				printSum(B, A);
				break;
			case 6:
				printMul(A, c);
				break;
			case 7:
				printMatrixMul(A, B);
				break;
			case 8:
				printMatrixMul(B, A);
				break;
			case 9:
				printNorm(A);
				break;
			case 10:
				printNorm(B);
				break;
			case 11:
				exit(0);
				break;
			default:
				std::cout << "choose number from 1 to 11\n";
		}
		std::cout << "\n\n";
	}

}

int main(int argc, const char *argv[])
{
	double type1;
	std::complex<double> type2;
	int Type = 0;
	const int DOUBLE = 1;
	const int COMPLEX = 2;

	std::cout << "Enter 1 to use real numbers, 2 to use complex numbers\n";
	std::cin >> Type;
	if (Type == DOUBLE)
	{
		interface(type1);
	}
	else if (Type = COMPLEX)
	{
		std::cout << "CAREFUL! Enter numbers like this: (real,imaginary)\n";
		interface(type2);
	}
	else
	{
		std::cout << "\nINCORRECT INPUT\n";
		system("pause");
	}
	return 0;
	return 0;
}