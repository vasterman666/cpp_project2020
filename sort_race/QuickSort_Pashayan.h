#pragma once
#include <vector>
using namespace std;

template<typename T>
int Separation(vector<T>& mass, int l, int r) {
    T x = mass[r];
    int less = l;

    for (int i = l; i < r; ++i) {
        if (mass[i] <= x) {
            swap(mass[i], mass[less]);
            ++less;
        }
    }
    swap(mass[less], mass[r]);
    return less;
}

template<typename T>
void QuickSortImpl(vector<T>& mass, int l, int r) {
    if (l < r) {
        int q = Separation(mass, l, r);
        QuickSortImpl(mass, l, q - 1);
        QuickSortImpl(mass, q + 1, r);
    }
}

template<typename T>
void QuickSort(vector<T>& mass) {
    if (!mass.empty()) {
        QuickSortImpl(mass, 0, mass.size() - 1);
    }
}

template<typename T>
vector<T> Quick_Sort(vector<T> mass) {
    QuickSort(mass);
    return mass;
}
