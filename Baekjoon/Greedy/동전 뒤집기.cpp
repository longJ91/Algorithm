// 문제 : https://www.acmicpc.net/problem/1285
// Greedy - 행의 조건을 강제 시킴
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
int result = 1000000;
void go(vector< vector<int> > map) {
	int temp = 0;
	vector<int> countOfColumn(N, 0);
	//Count the T of column
	for (int j = 0; j < N; j++) for (int i = 0; i < N; i++) map[i][j] == -1 ? countOfColumn[j]++ : 0;
	for (int j = 0; j < N; j++) countOfColumn[j] >= N / 2 ? temp += N - countOfColumn[j] : temp += countOfColumn[j];
	temp < result ? result = temp : 0;
}
void conditionLimit(int row, vector< vector<int> > map) {
	if (row == N) go(map);
	else {
		conditionLimit(row + 1, map);
		for (int j = 0; j < N; j++) map[row][j] *= -1;
		conditionLimit(row + 1, map);
	}
}
int main() {
	cin >> N;
	//T = -1, H = 1
	vector < vector<int> > map(N);
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) str.at(j) == 'T' ? map[i].push_back(-1) : map[i].push_back(1);
	}
	conditionLimit(0, map);
	cout << result;
	return 1;
}