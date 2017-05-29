// 문제 : https://www.acmicpc.net/problem/11656
// vector를 활용해서 분리된 문자열을 정렬
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(string A, string B) {
	return strcmp(A.c_str(), B.c_str()) < 0;
};
int main() {
	string str;
	vector<string> temp;
	int len;
	cin >> str;
	len = str.size();
	for (int i = 0; i < len; i++) temp.push_back(str.substr(i, len));
	sort(temp.begin(), temp.end(), compare);
	for (int i = 0; i < len; i++) cout << temp.at(i) << "\n";
	return 1;
}