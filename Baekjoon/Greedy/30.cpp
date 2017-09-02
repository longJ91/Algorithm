// 문제 : https://www.acmicpc.net/problem/10610
// Greedy - 30의 특성을 잘분석해야함 (마지막 자리가 0이면서, 각 자리의 합이 3으로 나누어 떨어져야함)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const int &a, const int &b) {
	return a > b;
}
int main() {
	string str;
	cin >> str;
	int lenOfStr = str.size();
	vector <int> number;
	for (int i = 0; i < lenOfStr; i++) number.push_back(str.at(i) - '0');
	sort(number.begin(), number.end(), cmp);
	string result = "";
	if (number.at(lenOfStr - 1) == 0) {
		int flag = 0;
		for (int i = 0; i < lenOfStr; i++) {
			result += to_string(number.at(i));
			flag += number.at(i);
		}
		if (flag % 3 != 0) result = "-1";
	}
	else result = "-1";
	cout << result;
	return 1;
}