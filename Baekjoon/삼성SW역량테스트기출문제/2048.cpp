// 문제 : https://www.acmicpc.net/problem/12100
// 삼성 SW 기출
// 1시간 35분
#include <iostream>
#include <vector>
using namespace std;
int result = 0;
//1 위, 2 아래, 3 왼쪽, 4 오른쪽 밀기
void push(const int direct, vector< vector<int> > &map) {
	int len = map.size();
	//위
	if (direct == 1) {
		for (int j = 0; j < len; j++) for (int i = 0; i < len; i++) {
			//first - index, second - value
			pair<int, int> one, two;
			one.second = two.second = 0;
			int flag = -1;
			for (int k = i; k < len; k++) {
				if (map[k][j] != 0) {
					if (one.second == 0) {
						one.second = map[k][j];
						one.first = k;
						flag = 0;
					}
					else if (two.second == 0 && one.second == map[k][j]) {
						two.second = map[k][j];
						two.first = k;
						flag = 1;
						break;
					}
					else break;
				}
			}
			if (flag == 1) {
				int temp = one.second * 2;
				map[one.first][j] = 0;
				map[two.first][j] = 0;
				map[i][j] = temp;
			}
			else if (flag == 0) {
				int temp = one.second;
				map[one.first][j] = 0;
				map[i][j] = temp;
			}
		}
	}
	//아래
	else if (direct == 2) {
		for (int j = 0; j < len; j++) for (int i = len - 1; i >= 0; i--) {
			//first - index, second - value
			pair<int, int> one, two;
			one.second = two.second = 0;
			int flag = -1;
			for (int k = i; k >= 0; k--) {
				if (map[k][j] != 0) {
					if (one.second == 0) {
						one.second = map[k][j];
						one.first = k;
						flag = 0;
					}
					else if (two.second == 0 && one.second == map[k][j]) {
						two.second = map[k][j];
						two.first = k;
						flag = 1;
						break;
					}
					else break;
				}
			}
			if (flag == 1) {
				int temp = one.second * 2;
				map[one.first][j] = 0;
				map[two.first][j] = 0;
				map[i][j] = temp;
			}
			else if (flag == 0) {
				int temp = one.second;
				map[one.first][j] = 0;
				map[i][j] = temp;
			}
		}
	}
	//왼쪽
	else if (direct == 3) {
		for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) {
			//first - index, second - value
			pair<int, int> one, two;
			one.second = two.second = 0;
			int flag = -1;
			for (int k = j; k < len; k++) {
				if (map[i][k] != 0) {
					if (one.second == 0) {
						one.second = map[i][k];
						one.first = k;
						flag = 0;
					}
					else if (two.second == 0 && one.second == map[i][k]) {
						two.second = map[i][k];
						two.first = k;
						flag = 1;
						break;
					}
					else break;
				}
			}
			if (flag == 1) {
				int temp = one.second * 2;
				map[i][one.first] = 0;
				map[i][two.first] = 0;
				map[i][j] = temp;
			}
			else if (flag == 0) {
				int temp = one.second ;
				map[i][one.first] = 0;
				map[i][j] = temp;
			}
		}
	}
	//오른쪽
	else {
		for (int i = 0; i < len; i++) for (int j = len - 1; j >= 0; j--) {
			//first - index, second - value
			pair<int, int> one, two;
			one.second = two.second = 0;
			int flag = -1;
			for (int k = j; k >= 0; k--) {
				if (map[i][k] != 0) {
					if (one.second == 0) {
						one.second = map[i][k];
						one.first = k;
						flag = 0;
					}
					else if (two.second == 0 && one.second == map[i][k]) {
						two.second = map[i][k];
						two.first = k;
						flag = 1;
						break;
					}
					else break;
				}
			}
			if (flag == 1) {
				int temp = one.second * 2;
				map[i][one.first] = 0;
				map[i][two.first] = 0;
				map[i][j] = temp;
			}
			else if (flag == 0) {
				int temp = one.second;
				map[i][one.first] = 0;
				map[i][j] = temp;
			}
		}
	}
}
void next(const int N, const int direct, vector< vector<int> > map) {
	push(direct, map);
	if (N == 5) {
		int len = map.size();
		for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) if (result < map[i][j]) result = map[i][j];
	}
	else {
		next(N + 1, 1, map);
		next(N + 1, 2, map);
		next(N + 1, 3, map);
		next(N + 1, 4, map);
	}
}
int main() {

	int N;
	cin >> N;
	vector < vector<int> > map(N);
	int value;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> value;
		map[i].push_back(value);
	}
	next(1, 1, map);
	next(1, 2, map);
	next(1, 3, map);
	next(1, 4, map);
	cout << result;
	return 1;
}