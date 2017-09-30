// 문제 : https://www.acmicpc.net/problem/5214
// 삼성 sw 대비
// 도시의 간선을 입력 받는 방식이 2개의 도시들만 들어오는 것이 아니라 저장하기가 곤란하다.
// 이 문제를 해결하기 위해 임의의 유령 도시를 만들어 연결시키고 저장한다. 마지막 최소 간선거리는 지나온 유령 도시 수 만큼 빼면 답을 구할수 있다
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N, K, M;
vector< vector<int> > info(101001);
//0 - 진짜 도시, 1 - 가짜 도시
int minCost[101001][2];
int main() {
	memset(minCost, -1, sizeof(minCost));
	cin >> N >> K >> M;
	int city;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> city;
			info[N + i].push_back(city);
			info[city].push_back(N + i);
		}
	}
	minCost[1][0] = 1;
	minCost[1][1] = 0;
	queue<int> bfs;
	bfs.push(1);
	int bfs_size = 1;
	while (bfs_size != 0) {
		int city_number = bfs.front();
		int len = info[city_number].size();
		bfs.pop(); bfs_size--;
		int next;
		for (int i = 0; i < len; i++) {
			next = info[city_number][i];
			if (minCost[next][0] == -1) {
				//가짜 도시
				if (next > N) {
					minCost[next][0] = minCost[city_number][0];
					minCost[next][1] = minCost[city_number][1] + 1;
				}
				else {
					minCost[next][0] = minCost[city_number][0] + 1;
					minCost[next][1] = minCost[city_number][1];
				}
				bfs.push(next); bfs_size++;
			}
			else {
				//최단 거리 값 갱신
				if (minCost[city_number][0] + minCost[city_number][1] + 1 < minCost[next][0] + minCost[next][1]) {
					//가짜 도시
					if (next > N) {
						minCost[next][0] = minCost[city_number][0];
						minCost[next][1] = minCost[city_number][1] + 1;
					}
					else {
						minCost[next][0] = minCost[city_number][0] + 1;
						minCost[next][1] = minCost[city_number][1];
					}
					bfs.push(next); bfs_size++;
				}
			}
		}
	}
	cout << minCost[N][0] << endl;
	return 1;
}