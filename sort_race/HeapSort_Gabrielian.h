#pragma once
#include <vector>

using namespace std;

// Функция нагромождения дерева
template <typename T>
void heapify(vector<T>& mass, size_t n, double first)
{
    double largest = first;
    int l = 2 * first + 1;
    int r = 2 * first + 2;

    if (l < n && mass[l] > mass[largest])
        largest = l;

    if (r < n && mass[r] > mass[largest])
        largest = r;

    if (largest != first)
    {
        swap(mass[first], mass[largest]);

        heapify(mass, n, largest);
    }
}

// Функция сортировки
template <typename T>
void heapSort(vector<T>& mass, size_t n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(mass, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(mass[0], mass[i]);

        heapify(mass, i, 0);
    }
}

template <typename T>
vector<T> HeapSort(vector<T> mass)
{
    size_t N = mass.size();
    heapSort(mass, N);
    return mass;
}