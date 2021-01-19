/*
File name: SortTimer.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

#ifndef SORTTIMER_H
#define SORTTIMER_H

#include "Sorts.h"
#include <time.h>

template <typename T>
class SortTimer
{
    public:

    double timeASort(void sort(T[], int), T arr[], int size);
};

#include "SortTimer.cpp"
#endif