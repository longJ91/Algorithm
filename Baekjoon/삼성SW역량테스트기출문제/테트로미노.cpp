// 문제 : https://www.acmicpc.net/problem/14500
// Brute force
#include <iostream>
using namespace std;
int map[501][501];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];
	int result = 0, temp = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		//길쭉이
		if (j + 3 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
			if (result < temp) result = temp;
		}
		if (i + 3 < N) {
			temp = 0;
			temp += map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
			if (result < temp) result = temp;
		}
		//정사각형
		if (i + 1 < N && j + 1 < M) {
			temp = 0;
			temp += map[i][j] + map[i + 1][j] + map[i][j+1] + map[i + 1][j+1];
			if (result < temp) result = temp;
		}
		//제일 쓰레기
		if (j + 1 < M && i + 2 < N) {
			temp = 0;
			temp += map[i][j] + map[i + 1][j] + map[i+1][j + 1] + map[i + 2][j + 1];
			if (result < temp) result = temp;
		}
		if (j + 2 < M && i - 1 >= 0) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2];
			if (result < temp) result = temp;
		}
		if (j + 1 < M && i + 1 < N && i - 1 >= 0) {
			temp = 0;
			temp += map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i - 1][j + 1];
			if (result < temp) result = temp;
		}
		if (j + 2 < M && i + 1 < N) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (result < temp) result = temp;
		}
		//니은
		if (i + 2 < N && j + 1 < M) {
			temp = 0;
			temp += map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
			if (result < temp) result = temp;
		}
		if (i - 1 >= 0 && j + 2 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
			if (result < temp) result = temp;
		}
		if (i + 2 < N && j + 1 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (result < temp) result = temp;
		}
		if (i + 1 < N && j + 2 < M) {
			temp = 0;
			temp += map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
			if (result < temp) result = temp;
		}
		//니은 대칭
		if (i - 2 >= 0 && j + 1 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 2][j + 1];
			if (result < temp) result = temp;
		}
		if (i + 1 < N && j + 2 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			if (result < temp) result = temp;
		}
		if (i + 2 < N && j + 1 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
			if (result < temp) result = temp;
		}
		if (i + 1 < N && j + 2 < M) {
			temp = 0;
			temp += map[i][j] + map[i + 1][j] + map[i+1][j + 1] + map[i+1][j + 2];
			if (result < temp) result = temp;
		}
		//뻐큐
		if (i - 1 >= 0 && j + 2 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
			if (result < temp) result = temp;
		}
		if (i - 1 >= 0 && j + 1 < M && i + 1 < N) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i + 1][j + 1];
			if (result < temp) result = temp;
		}
		if (i + 1 < N && j + 2 < M) {
			temp = 0;
			temp += map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if (result < temp) result = temp;
		}
		if (i + 2 < N && j + 1 < M) {
			temp = 0;
			temp += map[i][j] + map[i + 1][j] + map[i+2][j] + map[i + 1][j + 1];
			if (result < temp) result = temp;
		}
	}
	cout << result;
	return 1;
}