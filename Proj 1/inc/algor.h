#pragma once

#include <algorithm>
#include <iostream>
#include <cmath>
#include <chrono>

#define TYPE int

template<typename Tab>
void mergesort(Tab *Tablica_do_sort, Tab *Pomoc_Tablica, int first, int last);

template<typename Tab>
void quicksort(Tab *Tablica_do_sort, int first, int last);

template<typename Tab>
void introsort(Tab *Tablica_do_sort, int first, int last);

template<typename Tab>
TYPE partition (Tab *Tablica, int first, int last);

template<typename Tab>
void intro(Tab *Tablica_do_sort, Tab *left, Tab *right, int depth);

template<typename Tab>
void heap(Tab *first, Tab *last);

template<typename Tab>
void insertion(Tab *Tablica_do_sort, int first, int last);
