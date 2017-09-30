// ���� : https://www.acmicpc.net/problem/5214
// �Ｚ sw ���
// ������ ������ �Է� �޴� ����� 2���� ���õ鸸 ������ ���� �ƴ϶� �����ϱⰡ ����ϴ�.
// �� ������ �ذ��ϱ� ���� ������ ���� ���ø� ����� �����Ű�� �����Ѵ�. ������ �ּ� �����Ÿ��� ������ ���� ���� �� ��ŭ ���� ���� ���Ҽ� �ִ�
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N, K, M;
vector< vector<int> > info(101001);
//0 - ��¥ ����, 1 - ��¥ ����
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
				//��¥ ����
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
				//�ִ� �Ÿ� �� ����
				if (minCost[city_number][0] + minCost[city_number][1] + 1 < minCost[next][0] + minCost[next][1]) {
					//��¥ ����
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