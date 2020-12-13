
#include <vector>
#include <array>
#include <iostream>
using namespace std;

template <typename T>
void heap (vector<T>&data, int i, int n) //obrazovali heap
{
    int max = i;// index ielem = index maxelem while 
    
    while (true)
    {
        int son = 2 * i + 1;//left son
        if (son<n && data[son] > data[max])
            max = son;
        son++; // right son
        if (son < n && data[son] > data[max])
        max = son;
        if (max == i)
            break;
        else
        {
            swap(data[max], data[i]);
            i = max;
        }

    }
}
template <typename T>
void heapsort(vector<T>& data)// sortirovka vectora
{
    int n = size(data);
    for (int i = n / 2; i >= 0; i--)
        heap(data, i , data.size());
    for (int i = n - 1; i >= 1; i--)
    {
        swap(data[0], data[i]);
        heap(data, 0, i);
    }
}

vector<int> binaryheap(vector<int> data)
{
    heapsort(data);
    return data;
}
vector<double> binaryheap_double (vector<double> data) {
    heapsort(data);
    return data;
}

