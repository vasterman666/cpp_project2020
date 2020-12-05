#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int partition(vector<int>& data, int bottom, int top) {
	int left = bottom;
	int right = top;
	int middle = data.at((left + right) / 2);
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
		swap(data.at(left), data.at(right));
		left++;
		right--;
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
