#pragma once

#include "sequence.h"

#define INDEX_OUT_OF_RANGE_MESSAGE "index out of range"
#define NEGATIVE_SIZE_MESSAGE "size is negative"
#define ZERO_SIZE_MESSAGE "size is 0"
#define WRONG_SIZES_MESSAGE "operation is impossible because of the sizes"

using namespace std;

template <typename T>
class Matrix{
private:
	int rows = 0;
	int columns = 0;
	Sequence<Sequence<T>*> *data;
	
public:
	Matrix (int rows, int columns)
	{
		if(rows < 0 || columns < 0) throw std::length_error(NEGATIVE_SIZE_MESSAGE);
		this->rows = rows;
		this->columns = columns;
		data = (Sequence<Sequence<T>*>*) new ListSequence<ListSequence<T>*>;
		for(int i = 0; i < rows; i++)
		{
			data->append(new ListSequence<T>(columns));
		}
	}
	T get(int i, int j) const
	{
	if(i < 0 || i >= this->rows || j < 0 || j >= this->columns) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
	return data->get(i)->get(j);
	}
	void set(T item, int i, int j)
	{
	if(i < 0 || i >= this->rows || j < 0 || j >= this->columns)  throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
	
	data->get(i)->set(item, j);
	}

	int getRows() const {
		return this->rows;
	}

	int getColumns() const {
		return this->columns;
	}

	bool operator==(const Matrix<T> &matrix) const {
		if(this->rows != matrix.rows || this->columns != matrix.columns) return false;

		for(int i = 0; i < this->rows; i++)
			for(int j = 0; j < this->columns; j++)
				if(this->get(i, j) != matrix.get(i, j)) return false;
	
		return true;
	}

	T getNorm() const
	{
		T sum = 0;
		for(int i = 0; i < this->rows; i++)
			for(int j = 0; j < this->columns; j++)
			{
				sum = sum + abs((this->get(i, j)) * (this->get(i, j)));
			}

		return sqrt(sum);
	}
	Matrix<T>* operator+( const Matrix<T> &matrix) const
	{
		if( this->rows != matrix.rows || this->columns != matrix.columns) throw std::out_of_range(WRONG_SIZES_MESSAGE);
		
		Matrix<T> *newMatrix = new Matrix<T>(this->rows, this->columns);
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				T el = this->get(i, j) + matrix.get(i, j);
				newMatrix->set(el, i, j);
			}
		}
		return newMatrix;
	}
	Matrix<T>* operator*(const Matrix<T> &matrix) const
	{
		if( this->columns != matrix.rows) throw std::out_of_range(WRONG_SIZES_MESSAGE);
		Matrix<T> *newMatrix = new Matrix<T>(this->rows, this->columns);
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < matrix.columns; j++)
			{
				T sumij = 0;
				for (int k = 0; k < this->columns; k++)
				{
					sumij = sumij + this->get(i, k) * matrix.get(k, j);
				}
				newMatrix->set(sumij, i, j);
			}
		}
		return newMatrix;
	}
	template <typename U>
	Matrix<T>* scalarMult(U c) const
	{
		Matrix<T> *newMatrix = new Matrix<T>(this->rows, this->columns);
		for(int i = 0; i < this->rows; i++)
			for(int j = 0; j < this->columns; j++){
				newMatrix->set(this->get(i, j) * c, i, j);
			}
		return newMatrix;
	}
	void show()
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				T el = this->elements->get(i)->get(j);
				cout << el << " ";
			}
			cout << endl;
		}
	}
};
