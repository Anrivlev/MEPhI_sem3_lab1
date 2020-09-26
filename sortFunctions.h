#pragma once

#include "sequence.h"


template <class T>
bool asc(T a, T b)
{
    return a <= b;
}

template <class T>
bool desc(T a, T b)
{
    return a >= b;
}

template <class T>
void bubbleSort(Sequence<T> *seq, bool (*compare)(T, T))
{
    int size = seq->getSize();
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(compare(seq->get(i), seq->get(j)))
            {
                T tmp = seq->get(i);
                seq->set(seq->get(j), i);
                seq->set(tmp, j);
            }
        }
    }
}

template <class T>
void mergeSort(Sequence<T> *seq, bool (*compare)(T, T))
{
    _mergeSort_(seq, 0, seq->getSize() - 1, compare);
}

template <class T>
void _mergeSort_(Sequence<T> *seq, int l, int r, bool (*compare)(T,T))
{
    if(l == r) return;
    int mid = (r + 1) / 2;
    _mergeSort_(seq, l, mid, compare);
    _mergeSort_(seq, mid + 1, r, compare);
    int i = l;
    int j = mid + 1;
    ArraySequence<T> *arr;
    arr = new ArraySequence<T>(r);
    for(int step = 0; step < r - l + 1; step++)
    {
        if((j > r) || ((i <= mid) && (seq->get(i) < (seq->get(j)))))
        {
            arr->set(seq->get(i), step);
            i++;
        }
        else
        {
            arr->set(seq->get(j), step);
            j++;
        }
    }
    for(int step = 0; step < r - l + 1; step++)
        seq->set(arr->get(step), l + step);
}