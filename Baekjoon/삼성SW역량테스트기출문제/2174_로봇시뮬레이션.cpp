// 문제 : https://www.acmicpc.net/problem/2174
// 삼성 sw 대비
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct ROBOT {
	ROBOT() {}
	ROBOT(int X, int Y, char D) {
		x = X;
		y = Y;
		d = D;
	}
	int x, y;
	char d;
};
int A, B, N, M;
int map[101][101];
ROBOT robot[101];
int flag = 1;
void go(const int number, const char command) {
	int x = robot[number].x;
	int y = robot[number].y;
	char d = robot[number].d;
	if (d == 'E') {
		if (command == 'F') {
			if (x + 1 > A) {
				flag = -1;
				cout << "Robot " << number << " crashes into the wall";
				return;
			}
			else {
				for (int n = 1; n <= N; n++) {
					if (n == number) continue;
					if (x + 1 == robot[n].x && y == robot[n].y) {
						flag = -1;
						cout << "Robot " << number << " crashes into robot " << n;
						return;
					}
				}
			}
			robot[number].x = x + 1;
		}else if (command == 'L') {
			robot[number].d = 'N';
		}
		else {
			robot[number].d = 'S';
		}
	}
	else if (d == 'W') {
		if (command == 'F') {
			if (x - 1 < 1) {
				flag = -1;
				cout << "Robot " << number << " crashes into the wall";
				return;
			}
			else {
				for (int n = 1; n <= N; n++) {
					if (n == number) continue;
					if (x - 1 == robot[n].x && y == robot[n].y) {
						flag = -1;
						cout << "Robot " << number << " crashes into robot " << n;
						return;
					}
				}
			}
			robot[number].x = x - 1;
		}
		else if (command == 'L') {
			robot[number].d = 'S';
		}
		else {
			robot[number].d = 'N';
		}
	}
	else if (d == 'N') {
		if (command == 'F') {
			if (y + 1 > B) {
				flag = -1;
				cout << "Robot " << number << " crashes into the wall";
				return;
			}
			else {
				for (int n = 1; n <= N; n++) {
					if (n == number) continue;
					if (x == robot[n].x && y + 1 == robot[n].y) {
						flag = -1;
						cout << "Robot " << number << " crashes into robot " << n;
						return;
					}
				}
			}
			robot[number].y = y + 1;
		}
		else if (command == 'L') {
			robot[number].d = 'W';
		}
		else {
			robot[number].d = 'E';
		}
	}
	else if (d == 'S') {
		if (command == 'F') {
			if (y - 1 < 1) {
				flag = -1;
				cout << "Robot " << number << " crashes into the wall";
				return;
			}
			else {
				for (int n = 1; n <= N; n++) {
					if (n == number) continue;
					if (x == robot[n].x && y - 1== robot[n].y) {
						flag = -1;
						cout << "Robot " << number << " crashes into robot " << n;
						return;
					}
				}
			}
			robot[number].y = y - 1;
		}
		else if (command == 'L') {
			robot[number].d = 'E';
		}
		else {
			robot[number].d = 'W';
		}
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin >> A >> B >> N >> M;
	int x, y;
	char d;
	for (int n = 1; n <= N; n++) {
		cin >> x >> y >> d;
		robot[n] = ROBOT(x, y, d);
	}
	int number, cnt;
	char command;
	for (int m = 0; m < M; m++) {
		cin >> number >> command >> cnt;
		for (int c = 0; c < cnt; c++) {
			go(number, command);
			if (flag == -1) break;
		}
		if (flag == -1) break;
	}
	if (flag == 1) cout << "OK" << endl;
	return 1;
}