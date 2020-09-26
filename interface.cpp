#include <complex.h>
#include "sortFunctions.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void interface()
{

    int choose = 0;
    int size = -1;
    cout << "Enter the size of a sequence" << endl;
    while (size < 0)
    {
        cin >> size;
    }
    cout << endl;
    ArraySequence<int> *seq;
    cout << "Enter 1 to fill in the sequence with random numbers" << endl;
    cout << "Enter 2 to fill in the sequence manually" << endl;
    cin >> choose;
    cout << endl;
    int arr[size];
    switch (choose)
    {
        case 1:
            seq = new ArraySequence<int>(size);
            srand(time(0));
            for (int i = 0; i < size; i++)
            {
                seq->set(rand(), i);
            }
            break;
        case 2:
            cout << "Enter " << size << " numbers to fill in the sequence" << endl;
            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }
            cout << endl;
            seq = new ArraySequence<int>(arr, size);
            break;
        default:
            break;
    }
    delete arr;
    cout << "The sequence:";
    for (int i = 0; i < size; i++)
        cout << seq->get(i) << " ";
    cout << endl;
    cout << "Enter 1 to sort in descending order" << endl;
    cout << "Enter 2 to sort in ascending order" << endl;
    cin >> choose;
    bool (*cmp)(int, int);
    switch (choose)
    {
        case 1:
            cmp = desc;
            break;
        case 2:
            cmp = asc;
            break;
        default:
            break;
    }
    cout << "Enter 1 to use bubble sort" << endl;
    cout << "Enter 2 to use merge sort" << endl;
    cout << "Enter 3 to use quick sort" << endl;
    cin >> choose;
    cout << endl;
    switch (choose)
    {
        case 1:
            bubbleSort(seq, cmp);
            break;
        case 2:
            mergeSort(seq, cmp);
            break;
        case 3:
            quickSort(seq, cmp);
            break;
        default:
            break;
    }
    cout << "Sorted sequence:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << seq->get(i) << " ";
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    int choose = 0;
    while(true)
    {
        interface();
        cout << "Enter 1 to start again" << endl;
        cin >> choose;
        cout << endl;
        if (choose != 1) break;
    }
	return 0;
}