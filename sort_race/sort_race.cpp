// sort_race.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>

#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include "DataSetRegister.h"
#include "Participants.h"

using namespace std;

#define RUN(x) {                \
    Run(#x, x, data);           \
}
template <typename T>
void Run(string method_name, Participant<T> p, vector<T> data)
{
    auto start = chrono::system_clock::now();
    vector<T> res = p(data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    cout << method_name << "\t"
        << data.size() << "\t"
        << (is_sorted(res.begin(), res.end()) ? to_string(time) + "\tmcs" : "failed") << endl;
}

int main()
{
    auto intDataSets = GenerateIntDataSets();
    for (auto& ds : intDataSets)
    {
        cout << ds.description << endl << endl;
        auto& data = ds.data;
        RUN(std_sort);
        //run your method here


        cout << endl << "**************************" << endl << endl;
    }

    auto doubleDataSets = GenerateDoubleDataSets();
    for (auto& ds : doubleDataSets)
    {
        cout << ds.description << endl << endl;
        auto& data = ds.data;
        RUN(sort_for_integers_only);
        //run your method here


        cout << endl << "**************************" << endl << endl;
    }
}
#include <string>
#include <iostream>
#include"BitonicSort_Sharnin.h"
#include"MergeSort_Shuranskiy.h"
#include"HeapSort_Gabrielian.h"
#include"QuickSort_Pashayan.h"

using namespace std;

vector<int> GenerateData(int size, int max_value = INT_MAX);
vector<double> GenerateDataforDouble(int size);
using Participant = std::vector<int>(*)(std::vector<int>);
using Participantfordouble = std::vector<double>(*)(std::vector<double>);
void Run(string method_name, Participant p, vector<int> data);
void RunforDouble(string method_name, Participantfordouble p, vector<double> data);

#define RUN(x) {                \
    Run(#x, x, data);           \
}

#define RUNforDouble(x) {       \
    RunforDouble(#x, x, data);  \
}

//place your method name here
vector<int> std_sort(vector<int>);
vector<double> sort_for_integers_only(vector<double> data);


int main()
{
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        cout << "1-Целочисленные массивы\n";
        cout << "2-Вещественные массивы\n";
        cout << "3-Общая гонка с BitonicSort(т.к. он работает только на 2^n элементах)\n";
        cout << "4-Наборы данных\n";
        cout << "0-Выход\n";
        cout << "Введите номер действия\n";
        int i;
        while (true)
        {
            cin >> i;
            if (cin.fail() || i < 0 || i>4)
            {
                cout << "Введённые данные не корректны\n";
                cin.clear();
                cin.ignore(32767, '\n');
            }
            else
                break;

        }
        switch (i)
        {
        case 1:
        {
            const array<int, 4> N = { 10, 1'000, 10'000, 1'000'000 };
            const array<int, 4> N1 = { 8, 1'024, 8'192, 1'048'576 };
            for (int n : N)
            {
                auto data = GenerateData(n);
                RUN(std_sort);
                RUN(MergeSort);
                RUN(HeapSort);
                RUN(QuickSort_Pashayan);
                //run your method here            
            }
            for (int n : N1)
            {
                auto data = GenerateData(n);
                RUN(std_sort);
                RUN(Bitonic_Sort);
            }
            break;
        }
        case 2:
        {
            const array<int, 4> N = { 10, 1'000, 10'000, 1'000'000 };
            const array<int, 4> N1 = { 8, 1'024, 8'192, 1'048'576 };
            for (int n : N)
            {
                auto data = GenerateDataforDouble(n);
                RUNforDouble(sort_for_integers_only);
                RUNforDouble(MergeSort);
                RUNforDouble(HeapSort);
                RUNforDouble(QuickSort_Pashayan);
                //run your method here
            }
            for (int n : N1)
            {
                auto data = GenerateDataforDouble(n);
                RUNforDouble(sort_for_integers_only);
                RUNforDouble(Bitonic_Sort);
            }
            break;
        }
        case 3:
        {
            const array<int, 4> N1 = { 8, 1'024, 8'192, 1'048'576 };
            for (int n : N1)
            {
                auto data = GenerateData(n);
                RUN(std_sort);
                RUN(MergeSort);
                RUN(Bitonic_Sort);
                RUN(HeapSort);
                RUN(QuickSort_Pashayan);
            }
            break;
        }
        case 4:
        {
            cout << "Представлен только худший вариант набора данных так как средний и лучший вариант совпадают и его можно проследить в 1 2 и 3 пункте меню\n";
            vector<int> data{ 5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9,9,9,9,9,9,9,9,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9,9,9,9,9,9,9,9 ,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9,9,9,9,9,9,9,9 };
            RUN(std_sort);
            RUN(MergeSort);
            RUN(Bitonic_Sort);
            RUN(HeapSort);
            RUN(QuickSort_Pashayan);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            break;
        }
        }
    }
    
}
