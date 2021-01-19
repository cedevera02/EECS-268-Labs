/*
File name: Executive.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

#include "Executive.h"

Executive::Executive(int argc, char* argv[])
{
    m_MAX = 100000;

    if (argc == 7)
    {
        std::string s(argv[6]);
        if (s=="assert")
        {
            m_assert = true;
        }
    }
        m_sort = argv[1];
        m_file = argv[5];
        m_assert = false;
        int lower = std::stoi(argv[2]);
        int upper = std::stoi(argv[3]);
        int increment = std::stoi(argv[4]);
        m_creator = new ArrayCreator<int>(lower, upper, increment);
        m_array = m_creator->getArray();
        fillArray();
        if (m_assert)
        {
            testArraysAssert();
        }
        else
        {
            testArrays();
        }
}

Executive::~Executive()
{
    delete m_creator;
}

void Executive::fillArray()
{
    srand(time(NULL));

    int j = 0;
    for (int i = m_creator->getLower(); i <= m_creator->getUpper(); i+=m_creator->getIncrement())
    {
        for (int k = 0; k < i; k++)
        {
            m_array[j][k] = rand()%m_MAX;
        }
        j++;
    }
}

void Executive::printArray()
{
    int j = 0;
    for (int i = m_creator->getLower(); i <= m_creator->getUpper(); i+=m_creator->getIncrement())
    {
        for (int k = 0; k < i; k++)
        {
            std::cout << m_array[j][k] <<" ";
        }
        j++;
        std::cout << "\n";
    }
}

void Executive::testArrays()
{
    std::ofstream output;
    output.open(m_file);
    SortTimer<int> timer;

    output << m_sort << "Sort\n" << std::fixed;

    int j = 0;
    for (int i = m_creator->getLower(); i <= m_creator->getUpper(); i+=m_creator->getIncrement())
    {
        output << i << ", ";
        if (m_sort=="bubble")
        {
            output << timer.timeASort(Sorts<int>::bubbleSort, m_array[j], i) << "\n";
        }
        if (m_sort=="selection")
        {
            output << timer.timeASort(Sorts<int>::selectionSort, m_array[j], i) << "\n";
        }
        if (m_sort=="insertion")
        {
            output << timer.timeASort(Sorts<int>::insertionSort, m_array[j], i) << "\n";
        }
        if (m_sort=="merge")
        {
            output << timer.timeASort(Sorts<int>::mergeSort, m_array[j], i) << "\n";
        }
        if (m_sort=="quick")
        {
            output << timer.timeASort(Sorts<int>::quickSort, m_array[j], i) << "\n";
        }
        if (m_sort=="quickWithMedian")
        {
            output << timer.timeASort(Sorts<int>::quickSortWithMedian, m_array[j], i) << "\n";
        }
        j++;
    }
}

void Executive::testArraysAssert()
{
    std::ofstream output;
    output.open(m_file);
    SortTimer<int> timer;

    output << m_sort << "Sort\n" << std::fixed;

    int j = 0;
    for (int i = m_creator->getLower(); i <= m_creator->getUpper(); i+=m_creator->getIncrement())
    {
        output << i << ", ";
        if (m_sort=="bubble")
        {
            output << timer.timeASort(Sorts<int>::bubbleSort, m_array[j], i) << "\n";
            assert(Sorts<int>::isSorted(m_array[j],i));
        }
        if (m_sort=="selection")
        {
            output << timer.timeASort(Sorts<int>::selectionSort, m_array[j], i) << "\n";
            assert(Sorts<int>::isSorted(m_array[j],i));
        }
        if (m_sort=="insertion")
        {
            output << timer.timeASort(Sorts<int>::insertionSort, m_array[j], i) << "\n";
            assert(Sorts<int>::isSorted(m_array[j],i));
        }
        if (m_sort=="merge")
        {
            output << timer.timeASort(Sorts<int>::mergeSort, m_array[j], i) << "\n";
            assert(Sorts<int>::isSorted(m_array[j],i));
        }
        if (m_sort=="quick")
        {
            output << timer.timeASort(Sorts<int>::quickSort, m_array[j], i) << "\n";
            assert(Sorts<int>::isSorted(m_array[j],i));
        }
        if (m_sort=="quickWithMedian")
        {
            output << timer.timeASort(Sorts<int>::quickSortWithMedian, m_array[j], i) << "\n";
            assert(Sorts<int>::isSorted(m_array[j],i));
        }
        j++;
    }
    output.close();
}