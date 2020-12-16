#include <vector>

using namespace std;
template <typename T>
int partition_ahmatzyanov(vector<T>& data, int left, int right) {
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
void qSort_Ahmatzyanov(vector<T>& data, int left, int right) {
	int separator;
	if (left < right) {
		separator = partition_ahmatzyanov(data, left, right);
		if (left != separator)
			qSort_Ahmatzyanov(data, left, separator);
		if (right != separator + 1)
			qSort_Ahmatzyanov(data, separator + 1, right);
	}
}
vector<int> quickSort_by_Ahmatzyanov(vector<int> data) {
	qSort_Ahmatzyanov(data, 0, data.size()-1);
	return data;
}
vector<double> quickSort_by_Ahmatzyanov(vector<double> data) {
	qSort_Ahmatzyanov(data, 0, data.size() - 1);
	return data;
}