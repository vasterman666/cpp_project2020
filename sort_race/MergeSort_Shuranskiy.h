#pragma once
#include<vector>


using namespace std;

template <typename T>
void MergeMatrix(vector<T>& mass, size_t first, size_t last, size_t middle)//Функция слияния
{
	if ((last - first) == 1 && mass[first] > mass[last])
	{
		swap(mass[first], mass[last]);
		return;
	}
	vector<T> supportmass; 
	supportmass.resize(last - first + 1);
	size_t i = first;
	size_t j = middle + 1;
	size_t k = 0;	
	while (i <= middle && j <= last)
	{
		if (mass[i] > mass[j])
		{
			supportmass[k] = mass[j];
			k++;
			j++;
		}
		else
		{
			supportmass[k] = mass[i];
			k++;
			i++;
		}
	}
	while (i <= middle)
	{
		supportmass[k] = mass[i];
		k++;
		i++;
	}
	while (j <= last)
	{
		supportmass[k] = mass[j];
		k++;
		j++;
	}
	for (auto i = first; i <= last; i++)
	{
		int j = 0;
		mass[i] = supportmass[j];
		j++;
	}
}


template <typename T>
void MergeSort(vector<T>& mass, size_t first, size_t last)//Функция сортировки
{
	if (last <= first)
	{
		return;
	}
	size_t middle = first + (last - first) / 2;
	MergeSort(mass, first, middle);
	MergeSort(mass, middle + 1, last);
	MergeMatrix(mass, first, last, middle);
}

template <typename T>
vector <T> MergeSort(vector<T> mass)
{
	size_t first = 0;
	size_t last = mass.size() - 1;
	MergeSort(mass, first, last);
	return mass;
}
