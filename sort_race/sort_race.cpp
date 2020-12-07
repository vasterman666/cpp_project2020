// sort_race.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

vector<int> GenerateData(int size, int max_value = INT_MAX);
vector <int> readData(int size);
vector <double> GenerateDoubleData(int size);

using Participant = std::vector<int>(*)(std::vector<int>);
using ParticipantDouble = std::vector<double>(*)(std::vector<double>);

void Run(string method_name, Participant p, vector<int> data);
void RunDouble(string method_name, ParticipantDouble p, vector<double> data);

#define RUN(x) {                \
    Run(#x, x, data);           \
}
#define RUNDouble(x) {                \
    RunDouble(#x, x, data);           \
}

//place your method name here
vector<int> std_sort(vector<int>);
vector<double> std_sort_double(vector<double>);

vector <int> quickSort(vector <int>);
vector <double> quickSortDouble(vector <double>);

int main()
{
    const array<int, 4> N = { 10, 1'000, 10'000, 1'000'000 };
        //выбрать необходимый генератор/чтение из файла
    int i = getIntValue("Choose test type: \n 1)Int Generation \n 2)Double Generation \n 3)Read from file(100 elements): ", 1, 3);
    switch (i) {
        case 1: {
            for (int n : N) {
                auto data = GenerateData(n);
                //place ur method here
                RUN(std_sort);
                RUN(quickSort);
            }

            break;
        }
        case 2: {
            for (int n : N) {
                auto data = GenerateDoubleData(n);
                //place ur method here
                RUNDouble(std_sort_double);
                RUNDouble(quickSortDouble);
            }
            break;
        }
        case 3: {
            auto data = readData(100);
            //place ur method here
            RUN(std_sort);
            RUN(quickSort);

        }
    }
}
