/*
File name: Sorts.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

template <typename T>
void Sorts<T>::merge(T arr1[], int size1, T arr2[], int size2)
{
    int i = 0, j = 0, pos = 0;
    T buffer [size1+size2];
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            buffer[pos] = arr1[i];
            i++;
            pos++;
        }
        else
        {
            buffer[pos] = arr2[j];
            j++;
            pos++;
        }   
    }

    if (i < size1)
    {
        while (i <size1)
        {
            buffer[pos] = arr1[i];
            i++;
            pos++;
        }
    }

    if (j < size2)
    {
        while (j <size2)
        {
            buffer[pos] = arr2[j];
            j++;
            pos++;
        }
    }

    for (int z = 0; z < size1; z++)
    {
        arr1[z] = buffer[z];
    }

    for (int y = 0; y < size2; y++)
    {
        arr2[y] = buffer[y+size1];
    }
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
    int mid = ((last-first)/2 + first);
    T temp;
    T median[] = {arr[first], arr[mid], arr[last]};

    bubbleSort(median, 3);

    if (median[1] != arr[last])
    {
        if (median[1] == arr[first])
        {
            temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;
        }

        if (median[1] == arr[mid])
        {
            temp = arr[mid];
            arr[mid] = arr[last];
            arr[last] = temp;
        }
    }
}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
    int pivot, left, right;
    T temp;
    if (median)
    {
        setMedianPivot(arr, first, last);
    }

    pivot = last;

    left = first;
    right = last - 1;

    while (left != right)
    {
        while (arr[left] < arr[pivot] && left!= right)
        {
            left++;
        }
        while (arr[right] > arr[pivot] && left!= right)
        {
            right--;
        }
        if (arr[left] > arr[pivot] && arr[right] < arr[pivot])
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    if (arr[left] > arr[pivot])
    {
        temp = arr[left];
        arr[left] = arr[pivot];
        arr[pivot] = temp;
    }

    return left;
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
    if (first < last)
    {
        int setElement = partition(arr, first, last, median);
        quickSortRec(arr, first, setElement-1, median);
        quickSortRec(arr, setElement+1, last, median);
    }
}

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    T temp;
    for (int i = size-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
    T temp;
    int minPos = 0;
    for (int i = 0; i <= size-2; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[minPos])
            {
                minPos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
    T temp;
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (arr[j] < arr[j-1] && j > 0)
        {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
    if (size > 1)
    {
        int lSize = size/2;
        int rSize = size - lSize;
        T* leftArr = arr;
        T* rightArr = (arr+lSize);

        mergeSort(leftArr,lSize);
        mergeSort(rightArr,rSize);
        merge(leftArr, lSize, rightArr, rSize);
    }
}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
    quickSortRec(arr, 0, size-1, true);
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
    quickSortRec(arr, 0, size-1, false);
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
    bool truth = true;

    for (int i = 0; i < size-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            truth = false;
        }
    }

    return truth;
}