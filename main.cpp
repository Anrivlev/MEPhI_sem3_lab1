#include <iostream>
#include "sortFunctions.h"

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    int size = 0;
    int *A = new int[size];
    for(int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    ArraySequence<int> *arr;
    arr = new ArraySequence<int>(A, size);
    quickSort(arr, asc);
    for(int i = 0; i < size; i++) cout << arr->get(i) <<' ';
    system("pause");
    return 0;
}
