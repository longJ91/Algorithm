#include <iostream>

using namespace std;

int stack[1001];
int top;

void init() {
	top = -1;
}

void push(int data) {
	stack[++top] = data;
}

int pop() {
	return stack[top--];
}

int Size() {
	return top + 1;
}

bool empty() {
	if (top < 0) return true;
	return false;
}

bool visited[1001];

int C;
int V;//장소 수
int E;//간선 수
int n;//화재 장소 수
int m;//소방서 수

int arr_cnt[1001];
int arr_v[1001][1001];
int arr_time[1001][1001];
int arr_fire[1001];
int arr_station[1001];

int arr_temp[1001];
int arr_ret[1001];

void Solve() {
	init();
	for (int a = 1; a < 1001; ++a) {
		visited[a] = false;
		arr_temp[a] = 987654321;
	}
	for (int a = 0; a < m; ++a) {
		push(arr_station[a]);
		visited[arr_station[a]] = true;
		arr_temp[arr_station[a]] = 0;
	}
	while (!empty()) {
		int size = Size();
		for (int k = 0; k < size; ++k) {
			int now = pop();
			for (int i = 0; i < arr_cnt[now]; ++i) {
				int next = arr_v[now][i];
				if (visited[next]) {
					if (arr_temp[next] > arr_temp[now] + arr_time[now][next]) {
						arr_temp[next] = arr_temp[now] + arr_time[now][next];
						push(next);
					}
				}
				else {
					arr_temp[next] = arr_temp[now] + arr_time[now][next];
					visited[next] = true;
					push(next);
				}
			}
		}
	}
	for (int a = 0; a < n; ++a) {
		if (arr_ret[arr_fire[a]] > arr_temp[arr_fire[a]]) arr_ret[arr_fire[a]] = arr_temp[arr_fire[a]];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> C;
	for (int t = 0; t < C; ++t) {
		for (int k = 1; k < 1001; ++k) {
			arr_cnt[k] = 0;
			arr_ret[k] = 987654321;
		}
		scanf("%d %d %d %d", &V, &E, &n, &m);
		int a;
		int b;
		int time;
		for (int e = 0; e < E; ++e) {
			scanf("%d %d %d", &a, &b, &time);
			arr_v[a][arr_cnt[a]] = b;
			arr_time[a][b] = time;
			++arr_cnt[a];
			arr_v[b][arr_cnt[b]] = a;
			arr_time[b][a] = time;
			++arr_cnt[b];
		}
		for (int a = 0; a < n; ++a) {
			scanf("%d", &arr_fire[a]);
		}
		for (int a = 0; a < m; ++a) {
			scanf("%d", &arr_station[a]);
		}
		Solve();
		int result = 0;
		for (int a = 0; a < n; ++a) {
			result += arr_ret[arr_fire[a]];
		}
		printf("%d\n", result);
	}
	return 0;
}