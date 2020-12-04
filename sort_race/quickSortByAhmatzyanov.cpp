#include <vector>
#include <iterator>

using namespace std;

int partition(vector<int>& data, int left, int right) {
	int middle = (left + right) / 2;
	while (left <= right) {
		while (data[left] <= data[middle]) {
			left++;
		}
		while (data[right] > data[middle]) {
			right--;
		}
		if (left >= right) {
			break;
		}
		swap(data[left], data[right]);
	}
	return right;
}

void qSort(vector<int>& data, int left, int right) {
	int separator;
	if (left < right) {
		separator = partition(data, left, right);
		qSort(data, left, separator);
		qSort(data, separator + 1, right);
	}
}

vector<int> quickSort(vector<int> data) {
	qSort(data, 0, data.size()-1);
	return data;
}
