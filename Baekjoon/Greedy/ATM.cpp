// ¹®Á¦ : https://www.acmicpc.net/problem/11399
// Greedy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const int &a, const int &b) {
	return a < b;
}
int main() {
	int N, temp;
	vector <int> getTime;
	cin >> N;
	for (int i=0; i < N; i++) {
		cin >> temp;
		getTime.push_back(temp);
	}
	sort(getTime.begin(), getTime.end(), compare);
	int result = 0, timeOfPre = 0;
	for (int i = 0; i < N; i++) {
		result += timeOfPre + getTime.at(i);
		timeOfPre += getTime.at(i);
	}
	cout << result;
	return 1;
}