// 문제 : https://www.acmicpc.net/problem/14503
// 완전탐색?
#include<iostream>
using namespace std;
// 0 길, 1 벽
int map[50][50];
// 0 청소전, 1 청소후
int check[50][50];
int main() {

	int N, M;
	cin >> N >> M;
	//[d]바라보는 방향 - 0 북쪽, 1 동쪽, 2 남쪽, 3 서쪽 (위부터 시계 방향)
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i<N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];

	int flag = 0, result = 0;
	while (flag <= 4) {
		//2-3 조건 (후진)
		if (flag == 4) {
			//북쪽
			if (d == 0) {
				if (r + 1 <= N && map[r + 1][c] == 0) {
					r++;
					flag = 0;
					continue;
				}
			}
			//동쪽
			if (d == 1) {
				if (c - 1 >= 0 && map[r][c - 1] == 0) {
					c--;
					flag = 0;
					continue;
				}
			}
			//남쪽
			if (d == 2) {
				if (r - 1 >= 0 && map[r - 1][c] == 0) {
					r--;
					flag = 0;
					continue;
				}
			}
			//서쪽
			if (d == 3) {
				if (c + 1 <= M && map[r][c + 1] == 0) {
					c++;
					flag = 0;
					continue;
				}
			}
			//2-4 조건 (정지)
			break;
		}
		if (check[r][c] == 0) {
			check[r][c] = 1;
			result++;
			flag = 0;
			continue;
		}
		//2-1 조건, 2-2 조건 (왼쪽 청소 or 반시계 방향 회전)
		//북쪽
		if (d == 0) {
			//왼쪽 청소 가능
			if (c - 1 >= 0 && map[r][c - 1] == 0 && check[r][c - 1] == 0) {
				c--;
				d = 3;
				continue;
			}
			else {//왼쪽 청소 불가능
				d = 3;
				flag++;
				continue;
			}
		}
		//동쪽
		if (d == 1) {
			//왼쪽 청소 가능
			if (r - 1 >= 0 && map[r - 1][c] == 0 && check[r - 1][c] == 0) {
				r--;
				d = 0;
				continue;
			}
			else {//왼쪽 청소 불가능
				d = 0;
				flag++;
				continue;
			}
		}
		//남쪽
		if (d == 2) {
			//왼쪽 청소 가능
			if (c + 1 <= M && map[r][c + 1] == 0 && check[r][c + 1] == 0) {
				c++;
				d = 1;
				continue;
			}
			else {//왼쪽 청소 불가능
				d = 1;
				flag++;
				continue;
			}
		}
		//서쪽
		if (d == 3) {
			//왼쪽 청소 가능
			if (r + 1 <= N && map[r + 1][c] == 0 && check[r + 1][c] == 0) {
				r++;
				d = 2;
				continue;
			}
			else {//왼쪽 청소 불가능
				d = 2;
				flag++;
				continue;
			}
		}
	}
	cout << result;
	return 1;
}