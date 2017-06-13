// 문제 : https://www.acmicpc.net/problem/2178
// DFS 사용 못함. BFS 활용. BFS는 단계 별로 진행되기 때문에 도착 지점까지의 최소 값을 구할 수 있음
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
using namespace std;
int map[101][101];
int mapCheck[101][101];
int main() {
	int N, M;
	char enter;
	cin >> N >> M;
	enter = getc(stdin);
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= M; j++) map[i][j] = temp.at(j - 1) -'0';
	}
	//BFS
	queue< pair<int, int> > q;
	q.push(pair<int, int>(1, 1));
	mapCheck[1][1] += 1;
	while (!q.empty()) {
		int x, y;
		x = q.front().first;
		y = q.front().second;
		if (x - 1 >= 1 && map[x-1][y] == 1 && mapCheck[x - 1][y] == 0) {
			mapCheck[x - 1][y] = mapCheck[x][y] + 1;
			q.push(pair<int, int>(x - 1, y));
		}
		if (y + 1 <= M && map[x][y + 1] == 1 && mapCheck[x][y + 1] == 0) {
			mapCheck[x][y + 1] = mapCheck[x][y] + 1;
			q.push(pair<int, int>(x, y + 1));
		}
		if (x + 1 <= N && map[x + 1][y] == 1 && mapCheck[x + 1][y] == 0) {
			mapCheck[x + 1][y] = mapCheck[x][y] + 1;
			q.push(pair<int, int>(x + 1, y));
		}
		if (y - 1 >= 1 && map[x][y - 1] == 1 && mapCheck[x][y - 1] == 0) {
			mapCheck[x][y - 1] = mapCheck[x][y] + 1;
			q.push(pair<int, int>(x, y - 1));
		}
		q.pop();
	}
	cout << mapCheck[N][M] << endl;
	return 0;
}