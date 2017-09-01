// ¹®Á¦ : https://www.acmicpc.net/problem/1541
// Greedy
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int lenOfStr = str.size(), indexOfPre = 0, flag = 0;
	int result = 0;
	for (int i = 0; i < lenOfStr; i++) {
		if (str.at(i) == '+' || str.at(i) == '-') {
			if (flag == 0) {
				result += atoi(str.substr(indexOfPre, i).c_str());
				if (str.at(i) == '-') flag = 1;
			}
			else{
				result -= atoi(str.substr(indexOfPre, i).c_str());
			}
			indexOfPre = i+1;
		}
		if(i == lenOfStr - 1) flag == 0 ? result += atoi(str.substr(indexOfPre, i + 1).c_str()) : result -= atoi(str.substr(indexOfPre, i + 1).c_str());
	}
	cout << result;
	return 1;
}