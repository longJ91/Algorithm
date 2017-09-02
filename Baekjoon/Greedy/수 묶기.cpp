// ¹®Á¦ : https://www.acmicpc.net/problem/1744
// Greedy
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long result = 0;
bool cmpOfD(const int &a, const int &b) {
	return a > b;
}
bool cmpOfI(const int &a, const int &b) {
	return a < b;
}
int main() {
	int N;
	cin >> N;
	vector<int> zero;
	vector<int> minus;
	vector<int> plus;
	vector<int> one;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) zero.push_back(temp);
		else if (temp < 0) minus.push_back(temp);
		else if (temp == 1) one.push_back(temp);
		else plus.push_back(temp);
	}
	sort(plus.begin(), plus.end(), cmpOfD);
	sort(minus.begin(), minus.end(), cmpOfI);
	int lenOfPlus = plus.size(), lenOfMinus = minus.size(), lenOfOne = one.size();
	int pre = 0;
	for (int i = 0; i < lenOfPlus; i++) {
		if (i % 2 == 0) pre = plus.at(i);
		else {
			result += pre * plus.at(i);
			pre = 0;
		}
	}
	if (pre != 0) result += pre;
	for (int i = 0; i < lenOfOne; i++) result++;
	pre = 0;
	for (int i = 0; i < lenOfMinus; i++) {
		if (i % 2 == 0) pre = minus.at(i);
		else {
			result += pre * minus.at(i);
			pre = 0;
		}
	}
	if (pre != 0 && zero.empty()) result += pre;
	cout << result;
	return 1;
}