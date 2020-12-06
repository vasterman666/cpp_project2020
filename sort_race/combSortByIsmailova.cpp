#include <vector>
#include <string>

using namespace std;

vector <int> combSort(std::vector<int> data) // data Ч название вектора  (передаЄм по ссылке, чтобы вызов comb(array) мен€л вектор array)
{
    double factor = 1.2473309; // фактор уменьшени€
    int step = data.size() - 1; // шаг сортировки

    //ѕоследн€€ итераци€ цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1)
    {
        for (int i = 0; i + step < data.size(); i++)
        {
            if (data[i] > data[i + step])
            {
                std::swap(data[i], data[i + step]);
            }
        }
        step /= factor;
    }
    return data;
}


  