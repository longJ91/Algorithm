// 문제 : https://www.acmicpc.net/problem/1697
// BFS + check을 통해서 최소로 이미 지나온 숫자는 더 이상 작업을 하지않는다.
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct DATA {
	DATA(const int n_, const int cnt_) {
		n = n_;
		cnt = cnt_;
	}
	int n, cnt;
};
int check[100001];
int N, K;
int main() {
	memset(check, -1, sizeof(check));
	cin >> N >> K;
	queue<DATA> bfs;
	bfs.push(DATA(N, 0));
	check[N] = 0;
	int value, count;
	while (!bfs.empty()) {
		int len = bfs.size();
		for (int i = 0; i < len; i++) {
			value = bfs.front().n;
			count = bfs.front().cnt;
			bfs.pop();
			//-
			if (value - 1 >= 0) {
				if (check[value - 1] == -1) {
					check[value - 1] = count + 1;
					bfs.push(DATA(value - 1, count + 1));
				}
				else if (check[value - 1] > count + 1) {
					check[value - 1] = count + 1;
					bfs.push(DATA(value - 1, count + 1));
				}
			}
			//+
			if (value + 1 <= 100000) {
				if (check[value + 1] == -1) {
					check[value + 1] = count + 1;
					bfs.push(DATA(value + 1, count + 1));
				}
				else if (check[value + 1] > count + 1) {
					check[value + 1] = count + 1;
					bfs.push(DATA(value + 1, count + 1));
				}
			}
			//*
			if (value * 2 <= 100000) {
				if (check[value * 2] == -1) {
					check[value * 2] = count + 1;
					bfs.push(DATA(value * 2, count + 1));
				}
				else if (check[value * 2] > count + 1) {
					check[value * 2] = count + 1;
					bfs.push(DATA(value * 2, count + 1));
				}
			}
		}
		if (check[K] != -1) break;
	}
	cout << check[K] << endl;
	return 0;
}