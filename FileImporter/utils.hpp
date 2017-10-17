#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int strToInt(const string& str) {
	stringstream ss(str);
	int i;
	ss >> i;
	return i;
}

string intToStr(const int& i) {
	stringstream ss;
	ss << i;
	string str;
	ss >> str;
	return str;
}

vector<vector<string>> importData(const string& filename, const char& delimeter) {
	ifstream ifs(filename);
	vector<vector<string>> data;

	string line;
	while (getline(ifs, line)) {
		stringstream ssLine(line);

		string value;
		vector<string> vecLine;
		while (getline(ssLine, value, delimeter)) {
			vecLine.push_back(value);
		}
		data.push_back(vecLine);
	}
	return data;
}

void exportData(const string& filename, const char& delimeter, const bool& append, const vector<vector<string>>& data) {
	ofstream ofs;

	if (append) {
		ofs.open(filename, ofstream::app);
	}
	else {
		ofs.open(filename);
	}

	for (const vector<string>& vecString : data) {
		bool first = true;
		for (const string& str : vecString) {
			if (first) {
				ofs << str;
				first = false;
			}
			else {
				ofs << delimeter << str;
			}
		}
		ofs << endl;
	}
}
