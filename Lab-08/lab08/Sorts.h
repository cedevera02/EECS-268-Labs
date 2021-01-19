/*
File name: Sorts.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

#ifndef SORTS_H
#define SORTS_H

template <typename T>
class Sorts
{
    private:

    /**
     * @brief combines two sorted arrays into one sorted array
     * @param arr1[] 1st sorted array
     * @param size1 size of 1st array
     * @param arr2[] 2nd sorted array
     * @param size2 size of 2nd array
     */
    static void merge(T arr1[], int size1, T arr2[], int size2);

    /**
     * @brief partitions the array, chooses a pivot based on the median flag
     * if true, uses setMedianPivot, otherwise it uses the last element in arr
     * @param arr array to be partitioned
     * @param first index of first element in array
     * @param last index of last element in array
     * @param median determines what pivot point will be
     * @returns index of pivot point
     */
    static int partition(T arr[], int first, int last, bool median);
    
    /**
     * @brief looks at element at first, last, and the middle of array,
     * chooses the median from those three and sets up as last
     * @param arr array being looked at
     * @param first index of first element in array
     * @param last index of last element in array
     */
    static void setMedianPivot(T arr[], int first, int last);

    /**
     * @brief recursively calls partition until arr is in non-decreasing order
     * @param arr array to be partitioned
     * @param first index of first element in array
     * @param last index of last element in array
     * @param median determines what pivot point will be
     * @returns index of pivot point
     */
    static void quickSortRec(T arr[], int first, int last, bool median);

    public:

    /**
     * @brief sorts arr[] into non decreasing order
     * @param arr[] array to be sorted
     * @param size size of the array
     */
    static void bubbleSort(T arr[], int size);

    /**
     * @brief sorts arr[] into non decreasing order
     * @param arr[] array to be sorted
     * @param size size of the array
     */
    static void selectionSort(T arr[], int size);

    /**
     * @brief sorts arr[] into non decreasing order
     * @param arr[] array to be sorted
     * @param size size of the array
     */
    static void insertionSort(T arr[], int size);

    /**
     * @brief sorts arr[] into non decreasing order
     * @param arr[] array to be sorted
     * @param size size of the array
     */
    static void mergeSort(T arr[], int size);

    /**
     * @brief sorts arr[] into non decreasing order
     * @param arr[] array to be sorted
     * @param size size of the array
     */
    static void quickSort(T arr[], int size);

    /**
     * @brief sorts arr[] into non decreasing order (quick sort but sets median to true)
     * @param arr[] array to be sorted
     * @param size size of the array
     */
    static void quickSortWithMedian(T arr[], int size);

    /**
     * @brief iterates through the array and determines if it is in nondecreasing order
     * @param arr array to be checked
     * @param size size of the array
     * @return true if sorted false otherwise
     */
    static bool isSorted(T arr[], int size);
};

#include "Sorts.cpp"
#endif