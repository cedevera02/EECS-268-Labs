/*
File name: ArrayCreator.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

template <typename T>
ArrayCreator<T>::ArrayCreator(int lower, int upper, int increment)
{
    m_lowerBound = lower;
    m_upperBound = upper;
    m_increment = increment;
    createArray();
}

template <typename T>
ArrayCreator<T>::~ArrayCreator()
{
    int j =0;
    for (int i = m_lowerBound; i <=m_upperBound; i+=m_increment)
    {
        delete [] m_array[j];
        j++;
    }

    delete [] m_array;
}

template <typename T>
void ArrayCreator<T>::createArray()
{
    int j =0;
    for (int i = m_lowerBound; i <=m_upperBound; i+=m_increment)
    {
        j++;
    }

    m_array = new T*[j];

    int l = 0;
    for (int i = m_lowerBound; i <=m_upperBound; i+=m_increment)
    {
        m_array[l] = new T[i];
        l++;
    }
}

template <typename T>
T** ArrayCreator<T>::getArray() const
{
    return m_array;
}

template <typename T>
int ArrayCreator<T>::getLower() const
{
    return m_lowerBound;
}

template <typename T>
int ArrayCreator<T>::getUpper() const
{
    return m_upperBound;
}

template <typename T>
int ArrayCreator<T>::getIncrement() const
{
    return m_increment;
}