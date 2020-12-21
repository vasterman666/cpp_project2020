// AfanasevInsertSoft.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

template<typename T>
void insert_sort(std::vector<T>& aVector)
{
	unsigned end = aVector.size() - 1;
	for (unsigned i = end; i > 0; —i)
		if (larger(aVector[i - 1], aVector[i]))
			swap(aVector[i - 1], aVector[i]);

	for (unsigned i = 2; i <= end; ++i)
	{
		unsigned j = i;
		unsigned value = aVector[i];

		while (larger(aVector[j - 1], value))
		{
			aVector[j] = aVector[j - 1];
			—j;
		}
		aVector[j] = value;
	}
}
vector<int> AfanasevInsertSoft (vector<int> data)
{
	insert_sort(data);
	return data;
}

vector<double> AfanasevInsertSoft(vector<double> data)
{
	insert_sort(data);
	return data;
}