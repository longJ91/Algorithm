// 문제 : https://www.acmicpc.net/problem/2186
// brute force를 통한 재귀 함수 시간초과 발생, dfs는 메모리 초과 발생
// brute force OR dfs 무엇을 써도 상관 없다. 3차원 배열을 통해서 현재 좌표에서 구하려고 하는 단어의 인덱스를 보고 전에 구했던적에 있으면 그대로 값을 가져와서 사용.
// 결국 bf + dp
#include <iostream>
#include <string>
#include <queue>
using namespace std;
char map[100][100];
int dp[100][100][80];
int result = 0, len, k, n ,m;
string str;

int bf(const int i,const int j, const int str_index) {

	if (dp[i][j][str_index] != -1) {
		return dp[i][j][str_index];
	}
	if (str_index == len) {
		return 1;
	}
	dp[i][j][str_index] = 0;
	for (int s = 1; s <= k; s++) {
		//상
		if (i - s >= 0 && map[i - s][j] == str.at(str_index)) {
			dp[i][j][str_index] += bf(i - s, j, str_index + 1);
		}
		//하
		if (i + s < n && map[i + s][j] == str.at(str_index)) {
			dp[i][j][str_index] += bf(i + s, j, str_index + 1);
		}
		//좌
		if (j - s >= 0 && map[i][j - s] == str.at(str_index)) {
			dp[i][j][str_index] += bf(i, j - s, str_index + 1);
		}
		//우
		if (j + s < m && map[i][j + s] == str.at(str_index)) {
			dp[i][j][str_index] += bf(i, j + s, str_index + 1);
		}
	}
	return dp[i][j][str_index];
}

int main() {

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp.at(j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < 80; l++) {
				dp[i][j][l] = -1;
			}
		}
	}

	cin >> str;
	len = str.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str.at(0) == map[i][j]) {
				result += bf(i,j,1);
			}
		}
	}
	
	cout << result;
	return 1;
}