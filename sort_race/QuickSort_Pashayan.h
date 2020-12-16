#pragma once
#include <vector>
using namespace std;

template<typename T>
int Separation(vector<T>& mass, int low, int high) { // –азбиение Ћомуто(low и high Ч соответственно, нижн€€ и верхн€€ границы сортируемого участка этого массива)
    //T pivot = mass[high]; // выбираетс€ последний элемент (использовалось в ранних реализаци€х алгоритма, снижало производительность на отсортированных массивах)
    int mid;    
    mid = (low + high) / 2;
    if (mass[mid] < mass[low])
    { 
        swap (mass[low],mass[mid]);
    }
    if (mass[high] < mass[low])
    {
        swap(mass[low], mass[high]);
    }
    if (mass[mid] < mass[high])
    {
        swap(mass[high], mass[mid]);
    }
    T pivot = mass[high]; // дл€ улучшени€ эффективности в качестве опорного элемента выбираетс€ медиана первого, среднего и последнего элементов
    int less = low; // индекс less увеличиваетс€ каждый раз, когда находитс€ элемент, меньше или равный опорному => элемент вставл€етс€ перед опорным
    for (int i = low; i < high; ++i) {
        if (mass[i] <= pivot) {
            swap(mass[i], mass[less]);
            ++less;
        }
    }
    swap(mass[less], mass[high]);
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
vector<T> QuickSort_Pashayan(vector<T> mass) {
    QuickSort(mass);
    return mass;
}
