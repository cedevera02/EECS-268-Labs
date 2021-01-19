/*
File name: SortTimer.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

template <typename T>
double SortTimer<T>::timeASort(void sort(T[], int), T arr[], int size)
{
    clock_t start, end;

    start = clock();
    sort(arr,size);
    end = clock();

    return ((double)(end-start)/CLOCKS_PER_SEC);
}