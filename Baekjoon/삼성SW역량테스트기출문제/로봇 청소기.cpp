// ���� : https://www.acmicpc.net/problem/14503
// ����Ž��?
#include<iostream>
using namespace std;
// 0 ��, 1 ��
int map[50][50];
// 0 û����, 1 û����
int check[50][50];
int main() {

	int N, M;
	cin >> N >> M;
	//[d]�ٶ󺸴� ���� - 0 ����, 1 ����, 2 ����, 3 ���� (������ �ð� ����)
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i<N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];

	int flag = 0, result = 0;
	while (flag <= 4) {
		//2-3 ���� (����)
		if (flag == 4) {
			//����
			if (d == 0) {
				if (r + 1 <= N && map[r + 1][c] == 0) {
					r++;
					flag = 0;
					continue;
				}
			}
			//����
			if (d == 1) {
				if (c - 1 >= 0 && map[r][c - 1] == 0) {
					c--;
					flag = 0;
					continue;
				}
			}
			//����
			if (d == 2) {
				if (r - 1 >= 0 && map[r - 1][c] == 0) {
					r--;
					flag = 0;
					continue;
				}
			}
			//����
			if (d == 3) {
				if (c + 1 <= M && map[r][c + 1] == 0) {
					c++;
					flag = 0;
					continue;
				}
			}
			//2-4 ���� (����)
			break;
		}
		if (check[r][c] == 0) {
			check[r][c] = 1;
			result++;
			flag = 0;
			continue;
		}
		//2-1 ����, 2-2 ���� (���� û�� or �ݽð� ���� ȸ��)
		//����
		if (d == 0) {
			//���� û�� ����
			if (c - 1 >= 0 && map[r][c - 1] == 0 && check[r][c - 1] == 0) {
				c--;
				d = 3;
				continue;
			}
			else {//���� û�� �Ұ���
				d = 3;
				flag++;
				continue;
			}
		}
		//����
		if (d == 1) {
			//���� û�� ����
			if (r - 1 >= 0 && map[r - 1][c] == 0 && check[r - 1][c] == 0) {
				r--;
				d = 0;
				continue;
			}
			else {//���� û�� �Ұ���
				d = 0;
				flag++;
				continue;
			}
		}
		//����
		if (d == 2) {
			//���� û�� ����
			if (c + 1 <= M && map[r][c + 1] == 0 && check[r][c + 1] == 0) {
				c++;
				d = 1;
				continue;
			}
			else {//���� û�� �Ұ���
				d = 1;
				flag++;
				continue;
			}
		}
		//����
		if (d == 3) {
			//���� û�� ����
			if (r + 1 <= N && map[r + 1][c] == 0 && check[r + 1][c] == 0) {
				r++;
				d = 2;
				continue;
			}
			else {//���� û�� �Ұ���
				d = 2;
				flag++;
				continue;
			}
		}
	}
	cout << result;
	return 1;
}