// sort_race.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <array>
#include <vector>
#include <string>

using namespace std;

vector<int> GenerateData(int size, int max_value = INT_MAX);
vector <int> readData(int size);
vector <double> GenerateDoubleData(int size);
template <typename T>
using Participant = std::vector<T>(*)(std::vector<T>); 
template <typename T>
void Run(string method_name, Participant <T> p, vector<T> data);


#define RUN(x) {                \
    Run(#x, x, data);           \
}

//place your method name here
template <typename T>
vector<T> std_sort(vector<T>);
template <typename T>
vector <T> quickSort(vector <T>);

int main()
{
    const array<int, 4> N = { 10, 1'000, 10'000, 1'000'000 };
    for (int n : N)
    {
        //auto data = GenerateData(n);
        auto data = GenerateDoubleData(n);
        //auto data = readData(100);
        RUN(std_sort);
        RUN(quickSort);
    }
}
