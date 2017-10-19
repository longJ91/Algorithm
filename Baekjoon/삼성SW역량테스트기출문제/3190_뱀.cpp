// Problem : https://www.acmicpc.net/problem/3190
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int N, K, L, result;
int map[101][101];
//오른쪽, 왼쪽, 위, 아래
int move_x[4] = { 0, 0, -1, 1 };
int move_y[4] = { 1, -1, 0, 0 };
int main() {
	cin >> N >> K;
	int r, c;
	for (int k = 1; k <= K; k++) {
		cin >> r >> c;
		map[r][c] = 1;
	}
	int dir = 0;
	cin >> L;
	int V, flag;
	char D;
	vector<pair<int, int> > snake;
	pair<int, int> now = make_pair(1, 1);
	snake.push_back(now);
	result = 0;
	flag = 1;
	queue<pair<int, char> > instruction;
	for (int l = 1; l <= L; l++) {
		cin >> V >> D;
		instruction.push(make_pair(V, D));
	}
	while (true) {		
		result++;
		int cx, cy;
		cx = now.first + move_x[dir];
		cy = now.second + move_y[dir];
		if (cx > N || cx < 1 || cy > N || cy < 1) {
			flag = -1;
			break;
		}
		int snake_size = snake.size();
		for (int j = 0; j < snake_size; j++) {
			if (snake[j].first == cx && snake[j].second == cy) {
				flag = -1;
				break;
			}
		}
		if (flag == -1) break;
		snake.push_back(make_pair(cx, cy));
		if (map[cx][cy] != 1) snake.erase(snake.begin());
		else map[cx][cy] = 0;
		now.first = cx;
		now.second = cy;
		if (instruction.front().first != result) continue;
		D = instruction.front().second;
		if (dir == 0) {
			if (D == 'L') dir = 2;
			else dir = 3;
		}
		else if (dir == 1) {
			if (D == 'L') dir = 3;
			else dir = 2;
		}
		else if (dir == 2) {
			if (D == 'L') dir = 1;
			else dir = 0;
		}
		else {
			if (D == 'L') dir = 0;
			else dir = 1;
		}
		instruction.pop();
	}
	cout << result << endl;
	return 0;
}