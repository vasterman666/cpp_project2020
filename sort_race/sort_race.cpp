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
        //AhmatzyanovTeam
        RUN(binaryheap_by_Salikhova);
        RUN(tim_sort_by_Taishev);
        RUN(quickSort_by_Ahmatzyanov);
        RUN(merge_sort_by_Burlin);
        RUN(combSort_by_Ismailova);
        //run your method here


        cout << endl << "**************************" << endl << endl;
    }

    auto doubleDataSets = GenerateDoubleDataSets();
    for (auto& ds : doubleDataSets)
    {
        cout << ds.description << endl << endl;
        auto& data = ds.data;
        RUN(sort_for_integers_only);
        //AhmatzyanovTeam
        RUN(binaryheap_by_Salikhova);
        RUN(tim_sort_by_Taishev);
        RUN(quickSort_by_Ahmatzyanov);
        RUN(merge_sort_by_Burlin);
        //run your method here
      
      
        cout << endl << "**************************" << endl << endl;
    }
}