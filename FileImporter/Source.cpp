#include <iostream>
#include "utils.hpp"

using namespace std;

class User {
public:
	int id;
	string firstName, lastName, email, gender, ipAddress;

public:
	User(int id, string firstName, string lastName, string email, string gender, string ipAddress) :
		id(id), firstName(firstName), lastName(lastName), email(email), gender(gender), ipAddress(ipAddress) {};
};

class MockarooData {
public:
	vector<string> header;
	vector<User> users;
};

MockarooData fileDataToMockData(const vector<vector<string>>& data) {
	MockarooData md;
	md.header = data.front();

	for (int i = 1; i < data.size(); ++i) {
		md.users.push_back(User(strToInt(data[i][0]), data[i][1], data[i][2], data[i][3], data[i][4], data[i][5]));
	}

	return md;
}

vector<vector<string>> mockDataToFileData(const MockarooData& data) {
	vector<vector<string>> vvStr;
	vvStr.push_back(data.header);
	
	for (int i = 1; i < data.users.size(); ++i) {
		vvStr.push_back(vector<string>{intToStr(data.users[i].id), data.users[i].firstName, data.users[i].lastName, data.users[i].email, data.users[i].gender, data.users[i].ipAddress});
	}
	
	return vvStr;
}

int main() {
	vector<vector<string>> csvData = importData("MOCK_DATA.csv", ',');
	vector<vector<string>> txtData = importData("MOCK_DATA.txt", '\t');

	MockarooData csvMockData = fileDataToMockData(csvData);
	MockarooData txtMockData = fileDataToMockData(txtData);

	exportData("MOCK_DATA_OUT.csv", ',', false, mockDataToFileData(csvMockData));
	exportData("MOCK_DATA_OUT.txt", '\t', false, mockDataToFileData(txtMockData));
}