// 문제 : https://www.acmicpc.net/problem/14499
// 삼성 SW 역량테스트
#include <iostream>
#include <cstdio>
using namespace std;
int map[20][20];

int main() {
	int one, two, three, four, five, six;
	one = two = three = four = five = six = 0;
	int N, M;
	cin >> N >> M;
	int x, y, K;
	cin >> x >> y >> K;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];
	int command, temp;
	for (int k = 0; k < K; k++) {
		cin >> command;
		if (command == 1) {
			if (y + 1 < M) {
				y++;
				temp = one;
				one = three;
				three = six;
				six = four;
				four = temp;
				if (map[x][y] == 0) map[x][y] = one;
				else {
					one = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", six);
			}
		}
		else if (command == 2) {
			if (y - 1 >= 0) {
				y--;
				temp = one;
				one = four;
				four = six;
				six = three;
				three = temp;
				if (map[x][y] == 0) map[x][y] = one;
				else {
					one = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", six);
			}
		}
		else if (command == 3) {
			if (x - 1 >= 0) {
				x--;
				temp = one;
				one = two;
				two = six;
				six = five;
				five = temp;
				if (map[x][y] == 0) map[x][y] = one;
				else {
					one = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", six);
			}
		}
		else {
			if (x + 1 < N) {
				x++;
				temp = one;
				one = five;
				five = six;
				six = two;
				two = temp;
				if (map[x][y] == 0) map[x][y] = one;
				else {
					one = map[x][y];
					map[x][y] = 0;
				}
				printf("%d\n", six);
			}
		}
	}
	
	return 1;
}