#include <vector>
#include <isostream>
using namespace std;

void mSort(vector<int>& data, int first, int last)
{
	{
		if (first < last)
		{
			mSort(data, first, (first + last) / 2); //сортировка левой части
			mSort(data, (first + last) / 2 + 1, last); //сортировка правой части
			merg(data, first, last); //слияние двух частей
		}
	}
};


vector<int> merg_sort(vector<int>)
{
	mSort(data, 0,  data.size() - 1);
	return data;
}