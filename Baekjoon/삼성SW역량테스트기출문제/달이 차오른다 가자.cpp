// ���� : https://www.acmicpc.net/problem/1194
// �Ｚ sw ���
// BFS + �پ��� ������ ���� ����(��Ʈ����ũ)
// ������ ����� ���� a~z�������� �˰� ��Ʈ ����ũ ���Ǵµ�...
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int map[50][50];
int map_state[50][50][1 << 6];
struct MS {
	int x, y;
	int key;
};
int main() {
	memset(map_state, 0, sizeof(map_state));
	memset(map, -1, sizeof(map));
	cin >> N >> M;
	string str;
	MS start;
	int result;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '.') map[i][j] = 0;
			else if(str[j] == '#') map[i][j] = -1;
			else if (str[j] == '0') {
				map[i][j] = 0;
				start.x = i; start.y = j; start.key = 0;
			}else if (str[j] == '1') map[i][j] = 1;
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
	queue<MS> set;
	set.push(start);
	int set_size = 1;
	int R = result = -1;
	while (set_size != 0) {
		result++;
		int temp_size = set.size();
		for (int k = 0; k < temp_size; k++) {
			MS now = set.front();
			set.pop(); set_size--;
			//���� ��ġ Ȯ���ؼ�, Ű ì���, ��乮 ����, ����
			if (map[now.x][now.y] == 1) {
				set_size = 0;
				R = result;
				break;
			}
			//����
			else if (map[now.x][now.y] >= 42 && map[now.x][now.y] <= 67) {
				now.key = now.key | (1 << (map[now.x][now.y] - 10 - 32));
			}
			//��乮
			else if (map[now.x][now.y] >= 10 && map[now.x][now.y] <= 35) {
				if ((now.key & (1 << (map[now.x][now.y] - 10))) == false) continue;
			}
			//�̵��ϱ�
			if (now.x - 1 >= 0 && map[now.x - 1][now.y] >= 0) {
				int flag = -1;
				if (map_state[now.x - 1][now.y][now.key] == 0) {
					flag = 1;
					map_state[now.x - 1][now.y][now.key] = 1;
				}
				if (flag == 1) {
					MS next;
					next.x = now.x - 1; next.y = now.y; next.key = now.key;
					set.push(next); set_size++;
				}
			}
			//�̵��ϱ�
			if (now.x + 1 < N && map[now.x + 1][now.y] >= 0) {
				int flag = -1;
				if (map_state[now.x + 1][now.y][now.key] == 0) {
					flag = 1;
					map_state[now.x + 1][now.y][now.key] = 1;
				}
				if (flag == 1) {
					MS next;
					next.x = now.x + 1; next.y = now.y; next.key = now.key;
					set.push(next); set_size++;
				}
			}
			//�̵��ϱ�
			if (now.y - 1 >= 0 && map[now.x][now.y - 1] >= 0) {
				int flag = -1;
				if (map_state[now.x][now.y - 1][now.key] == 0) {
					flag = 1;
					map_state[now.x][now.y - 1][now.key] = 1;
				}
				if (flag == 1) {
					MS next;
					next.x = now.x; next.y = now.y - 1; next.key = now.key;
					set.push(next); set_size++;
				}
			}
			//�̵��ϱ�
			if (now.y + 1 < M && map[now.x][now.y + 1] >= 0) {
				int flag = -1;
				if (map_state[now.x][now.y + 1][now.key] == 0) {
					flag = 1;
					map_state[now.x][now.y + 1][now.key] = 1;
				}
				if (flag == 1) {
					MS next;
					next.x = now.x; next.y = now.y + 1; next.key = now.key;
					set.push(next); set_size++;
				}
			}
		}
	}
	cout << R << endl;
	return 1;
}