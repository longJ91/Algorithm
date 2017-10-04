// 문제 : https://www.acmicpc.net/problem/2493
// 삼성 sw 대비
// 특정 조건을 바탕으로 탐색을 줄여봄
#include <iostream>
#include <cstdio>
using namespace std;
int N, MIN, MAX;
int top[500001];
int result[500001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		//scanf("%d", top + i);
		cin >> top[i];
	}
	result[1] = 0;
	MIN = MAX = top[1];
	int now;
	for (int i = 2; i <= N; i++) {
		now = top[i];
		if (MIN > now) {
			MIN = now;
			result[i] = i - 1;
		}
		else if (MAX < now) {
			MAX = now;
			result[i] = 0;
		}
		else {
			for (int j = i - 1; j >= 1; j--) {
				if (top[j] > now) {
					result[i] = j;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		//printf("%d ", result[i]);
		cout << result[i] << " ";
	}
	return 1;
}