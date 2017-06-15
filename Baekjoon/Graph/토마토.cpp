// 문제 : https://www.acmicpc.net/problem/7576
// BFS 활용. 시작점이 정해지지 않고 토마토가 들어 있는 모든 상자에서 동시에 출발 해야함
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int map[1001][1001];
bool mapCheck[1001][1001];
int main() {
	int M, N, cnt = 0, max;
	cin >> M >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> map[i][j];
	queue< pair<int, int> > q;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
		if (map[i][j] == 1) {
			q.push(pair<int, int>(i, j));
			mapCheck[i][j] = true;
		}
		else if (map[i][j] == -1) cnt++;
	}
	if (q.size() + cnt== N * M) cout << 0 << endl;
	else {
		int count = 0;
		while (!q.empty()) {
			int x, y;
			x = q.front().first;
			y = q.front().second;
			max = map[x][y];
			if (y - 1 >= 1 && map[x][y - 1] != -1 && mapCheck[x][y - 1] == false) {
				q.push(pair<int, int>(x, y - 1));
				mapCheck[x][y - 1] = true;
				map[x][y - 1] = max + 1;
			}
			if (y + 1 <= M && map[x][y + 1] != -1 && mapCheck[x][y + 1] == false) {
				q.push(pair<int, int>(x, y + 1));
				mapCheck[x][y + 1] = true;
				map[x][y + 1] = max + 1;
			}
			if (x - 1 >= 1 && map[x - 1][y] != -1 && mapCheck[x - 1][y] == false) {
				q.push(pair<int, int>(x - 1, y));
				mapCheck[x - 1][y] = true;
				map[x - 1][y] = max + 1;
			}
			if (x + 1 <= N && map[x + 1][y] != -1 && mapCheck[x + 1][y] == false) {
				q.push(pair<int, int>(x + 1, y));
				mapCheck[x + 1][y] = true;
				map[x + 1][y] = max + 1;
			}
			q.pop();
			count++;
		}
		count + cnt == N * M ? cout << max - 1 << endl : cout << - 1 << endl;
	}
	return 0;
}