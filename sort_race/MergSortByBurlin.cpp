#include <iostream>
#include <vector>

using namespace std;
//
//template <typename T>
//void MergeSort(vector<T>& data, size_t first, size_t last)
//{
//	// в начале рассмотрим проSстейшие случаи
//	if (last - first < 2) //если в векторе 1 или 0 эл. (уже отсортирован)
//		return;
//	if (last - first == 2) //если в векторе 2 эл.
//	{
//        T a = first + 1;
//		if (data.at(first) > data.at(a))
//			swap(data.at(first), data.at(a));
//		return;
//	}
//
//	MergeSort(data, first, first + (last - first) / 2);
//	MergeSort(data, first + (last - first) / 2, last);
//
//	vector<int> v;
//	T left = first;
//	T middle = first + (last - first) / 2;
//	T right = middle ;
//
//	while (v.size() < last - first)
//	{
//		if (left >= middle || (right < last && data.at(right) <= data.at(left)))
//		{
//			v.push_back(data.at(right));
//			++right;
//		}
//		else
//		{
//			v.push_back(data.at(left));
//			++left;
//		}
//	}
//
//	for (size_t i = first; i < last; ++i)
//	{
//	    T a = i - first;
//		data.at(i) = v[a];
//	}
//}

//vector<int> merge_sort(vector<int> data)
//{
//	MergeSort(data, 0, data.size() - 1);
//	return data;
//}

/*
vector<double> merge_sort_double(vector<double> data)
{
	MergeSort(data, 0, data.size() - 1);
	return data;
}
*/


//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 20; ++i)
//		v.push_back(i);
//	for (size_t i = 0; i < v.size(); ++i)
//		swap(v[i], v[rand() % (v.size() - i) + i]);
//	for (auto i : v)
//		cout << i << " ";
//	cout << endl;
//
//	MergeSort(v, 0, v.size());
//	for (auto i : v)
//		cout << i << " ";
//	cout << endl;
//
//}


template <typename T>
void merge(vector<T>& data, int first, int last) 
{
	int left_it, right_it, middle, j;
	int *mas; //объявление указательного инта
	int a = last - first;
	mas = (int*)malloc((a) * sizeof(int)); //указатель инициализируется адресом первой интовой ячейкой из последовательности яечеек 
	                                                 //(размер - разница последнего и первого элемента)

	middle = (first + last) / 2;
	left_it = first;
	right_it = middle + 1;

	for (j = first; j <= last; j++) //цикл, итератор которого пробегает от индекса начала до индекса конца
		if ((left_it <= middle) && ((right_it > last) || (data[left_it] < data[right_it])))
		{
			*(mas + j - first) = data[left_it];
			left_it++;
		}
		else
		{
			*(mas + j - first) = data[right_it];
			right_it++;
		}
	//возвращение результата в список
	for (j = first; j <= last; j++) data[j] = *(mas + j - first);
};

template <typename T>
void MergeSort(vector<T>& data, int first, int last)
{
	{
		if (first < last)
		{
			MergeSort(data, first, (first + last) / 2); //сортировка первой(левой) части
			MergeSort(data, (first + last) / 2 + 1, last); //сортировка последней(правой) части
			merge(data, first, last); //слияние двух частей
		}
	}
}; 


vector<int> merge_sort_by_Burlin(vector<int> data)
{
	MergeSort(data, 0,  data.size() - 1);
	return data;
}
vector<double> merge_sort_by_Burlin(vector<double> data)
{
	MergeSort(data, 0, data.size() - 1);
	return data;
}