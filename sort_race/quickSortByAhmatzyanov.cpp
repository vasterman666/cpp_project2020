#include <vector>
//#include <iterator>
//#include <iostream>
using namespace std;
template <typename T>
int partition(vector<T>& data, int left, int right) {
	T middle = data.at((left + right) / 2);
	while (left <= right) {
		while (data.at(left) < middle) {
			left++;
		}
		while (data.at(right) > middle) {
			right--;
		}
		if (left >= right) {
			break;
		}
		T buffer = data.at(left);
		data.at(left) = data.at(right);
		data.at(right) = buffer;
		//swap(data.at(left), data.at(right)); <- медленно 
		left++;
		right--;
	}
	return right;
}
template <typename T>
void qSort(vector<T>& data, int left, int right) {
	int separator;
	if (left < right) {
		separator = partition(data, left, right);
		if (left != separator)
			qSort(data, left, separator);
		if (right != separator + 1)
			qSort(data, separator + 1, right);
	}
}

vector<int> quickSort(vector<int> data) {
	qSort(data, 0, data.size()-1);
	return data;
}
vector<double> quickSortDouble(vector<double> data) {
	qSort(data, 0, data.size() - 1);
	return data;
}