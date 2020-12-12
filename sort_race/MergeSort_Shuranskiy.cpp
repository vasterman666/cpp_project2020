#include<vector>


using namespace std;


template <typename T>
void MergeMatrix(vector<T>& mass, size_t first, size_t last, size_t middle)//Функция слияния
{

}


template <typename T>
vector <T> MergeSort(vector<T> mass, size_t first, size_t last)//Функция сортировки
{
	if(last<=first)
		return mass;
	size_t middle = first + (last - first) / 2;
	MergeSort(mass, first, middle);
	MergeSort(mass, middle + 1, last);
	MergeMatrix(mass, first, last, middle);
}