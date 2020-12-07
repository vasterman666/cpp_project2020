#include <vector>
#include <chrono>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

using Participant = std::vector<int>(*)(std::vector<int>);

void Run(string method_name, Participant p, vector<int> data)
{
	auto start = chrono::system_clock::now();
	vector<int> res = p(data);
	auto stop = chrono::system_clock::now();
	auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

	cout << method_name << "\t"
		<< data.size() << "\t"
		<< (is_sorted(res.begin(), res.end()) ? to_string(time) + "\tmcs" : "failed") << endl;
}

string getName()
{
	string name;
	cout << "Write text name with .txt: ";
	getline(cin, name);
	return name;
}

vector<int> GenerateData(int size, int max_value = INT_MAX)
{
	//generate random data or read data from your file
	vector<int> data(size);
	for (int& d : data)
		d = rand() % max_value;
	return data;
}

vector<int> readData(int size) {
	vector<int> data(size);
	ifstream fin;
	fin.open(getName(), ios::in);
	if (fin.is_open()) {
		for (int i = 0; i < size; i++) {
			fin >> data.at(i);
		}
	}
	else {
		cout << "There is no such file! \n";
	}
	fin.close();
	return data;
}