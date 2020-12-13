// sort_race.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <array>
#include <vector>
#include <string>
#include <iostream>

#include"MergeSort_Shuranskiy.h"

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
        cout << "3-Наборы данных\n";
        cout << "0-Выход\n";
        cout << "Введите номер действия\n";
        int i;
        while (true)
        {
            cin >> i;
            if (cin.fail() || i < 0 || i>3)
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
            for (int n : N)
            {
                auto data = GenerateData(n);
                RUN(std_sort);
                RUN(MergeSort);
                //run your method here            
            }
            break;
        }
        case 2:
        {
            const array<int, 4> N = { 10, 1'000, 10'000, 1'000'000 };
            for (int n : N)
            {
                auto data = GenerateDataforDouble(n);
                RUNforDouble(sort_for_integers_only);
                RUNforDouble(MergeSort);
                //run your method here
            }
            break;
        }
        case 3:
        {
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
