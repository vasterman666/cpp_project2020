#include<vector>
using namespace std;

template <typename T>
void ShellSort(vector<T>& aVector)
{
    unsigned end = aVector.size() - 1;
    unsigned h;
    for (h = 1; h <= end / 9; h = 3 * h + 1)
        ;

    for (; h > 0; h /= 3)
        for (auto i = h; i <= end; i++)
        {
            unsigned j = i;
            T v = aVector[i];
            while (j >= h && v < aVector[j - h])
            {
                aVector[j] = aVector[j - h];
                j -= h;
            }
            aVector[j] = v;
        }
}

vector<int> ShellSort_Kirillov(vector<int> data)
{
    ShellSort(data);
    return data;
}

vector<double> ShellSort_Kirillov(vector<double> data)
{
    ShellSort(data);
    return data;
}
