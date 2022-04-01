#include "algor.h"

//Przez scalanie
template<typename Tab>
void mergesort(Tab *Tablica_do_sort, Tab *Pomoc_Tablica, int first, int last)
{
    if (first == last) return;
    int mid = (first + last) / 2;
    mergesort(Tablica_do_sort, Pomoc_Tablica, first, mid);
    mergesort(Tablica_do_sort, Pomoc_Tablica, mid + 1, last);
    int i = first;
    int j = mid + 1;
    for (int step = 0; step < last - first + 1; step++)
    {
        if ((j > last) || ((i <= mid) && (Tablica_do_sort[i] < Tablica_do_sort[j])))
        {
            Pomoc_Tablica[step] = Tablica_do_sort[i];
            i++;
        }
        else
        {
            Pomoc_Tablica[step] = Tablica_do_sort[j];
            j++;
        }
    }
    for (int step = 0; step < last - first + 1; step++)
    Tablica_do_sort[first + step] = Pomoc_Tablica[step];
}


//Quicksort
template<typename Tab>
void quicksort(Tab *Tablica_do_sort, int first, int last)
{
    if (first < last)
    {
        int pivot = partition (Tablica_do_sort, first, last);
        quicksort(Tablica_do_sort, first, pivot);
        quicksort(Tablica_do_sort, pivot + 1, last);
    }
}

template<typename Tab>
TYPE partition (Tab *Tablica, int first, int last)
{
    Tab pivot = Tablica[(first + last) / 2];
    int i = first;
    int j = last;
    while (true)
    {
        while (Tablica[j] > pivot) j--;
        while (Tablica[i] < pivot) i++;
        if (i < j)
        {
            std::swap(Tablica[i++], Tablica[j--]);
        }
        else return j;
    }
}


//Introspektywne
template<typename Tab>
void introsort(Tab *Tablica_do_sort, int first, int last)
{
    int depth = log(last + 1) * 2;
    intro(Tablica_do_sort, Tablica_do_sort, Tablica_do_sort + last, depth);
}


template<typename Tab>
void intro(Tab *Tablica_do_sort, Tab *left, Tab *right, int depth)
{
    if ((right - left) < 20) insertion(Tablica_do_sort, left - Tablica_do_sort, right - Tablica_do_sort);
    else if (depth == 0) heap(left, right + 1)/*heap(Tablica_do_sort, last)*/;
    else
    {
        int pivot = partition(Tablica_do_sort, left - Tablica_do_sort, right - Tablica_do_sort);
        intro(Tablica_do_sort, left, Tablica_do_sort + pivot, depth - 1);
        intro(Tablica_do_sort, Tablica_do_sort + pivot + 1, right, depth - 1);
    }
}


template<typename Tab>
void heap(Tab *first, Tab *last)
{
    std::make_heap(first, last);
    std::sort_heap(first, last);
}


template<typename Tab>
void insertion(Tab *Tablica_do_sort, int first, int last)
{
    for (int i = first + 1; i <= last; i++)
    {
        int pivot = Tablica_do_sort[i];
        int j = i;
        while (j > first && Tablica_do_sort[j - 1] > pivot)
        {
            Tablica_do_sort[j] = Tablica_do_sort[j - 1];
            j--;
        }
        Tablica_do_sort[j] = pivot;
    }
}


template void mergesort<TYPE>(TYPE*, TYPE*, int, int);
template void quicksort<TYPE>(TYPE*, int, int);
template void introsort<TYPE>(TYPE*, int, int);
template void intro<TYPE>(TYPE*, TYPE*, TYPE*, int);
template void heap<TYPE>(TYPE*, TYPE*);
template void insertion<TYPE>(TYPE*, int, int);

