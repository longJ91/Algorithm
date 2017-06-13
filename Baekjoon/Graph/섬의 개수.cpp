// 문제 : https://www.acmicpc.net/problem/4963
// DFS 활용
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
int map[101][101];
bool mapCheck[101][101];
using namespace std;
int main() {
	int W = 1, H = 1;
	vector<int> result;

	while (!(W == 0 && H == 0)) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) cin >> map[i][j];
		stack< pair<int, int> > S;
		int total = 0;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (map[i][j] == 1 && mapCheck[i][j] == false) {
					S.push(pair<int, int>(i, j));
					mapCheck[i][j] = true;
				}
				//DFS
				while (!S.empty()) {
					int I, J;
					I = S.top().first;
					J = S.top().second;
					if (I - 1 >= 1 && map[I - 1][J] == 1 && mapCheck[I - 1][J] == false) {
						S.push(pair<int, int>(I - 1, J));
						mapCheck[I - 1][J] = true;
						continue;
					}
					if (I - 1 >= 1 && J + 1 <= W && map[I - 1][J + 1] == 1 && mapCheck[I - 1][J + 1] == false) {
						S.push(pair<int, int>(I - 1, J + 1));
						mapCheck[I - 1][J + 1] = true;
						continue;
					}
					if (J + 1 <= W && map[I][J + 1] == 1 && mapCheck[I][J + 1] == false) {
						S.push(pair<int, int>(I, J + 1));
						mapCheck[I][J + 1] = true;
						continue;
					}
					if (J + 1 <= W && I + 1 <= H && map[I + 1][J + 1] == 1 && mapCheck[I + 1][J + 1] == false) {
						S.push(pair<int, int>(I + 1, J + 1));
						mapCheck[I + 1][J + 1] = true;
						continue;
					}
					if (I + 1 <= H && map[I + 1][J] == 1 && mapCheck[I + 1][J] == false) {
						S.push(pair<int, int>(I + 1, J));
						mapCheck[I + 1][J] = true;
						continue;
					}
					if (J - 1 >= 1 && I + 1 <= H && map[I + 1][J - 1] == 1 && mapCheck[I + 1][J - 1] == false) {
						S.push(pair<int, int>(I + 1, J - 1));
						mapCheck[I + 1][J - 1] = true;
						continue;
					}
					if (J - 1 >= 1 && map[I][J - 1] == 1 && mapCheck[I][J - 1] == false) {
						S.push(pair<int, int>(I, J - 1));
						mapCheck[I][J - 1] = true;
						continue;
					}
					if (I - 1 >= 1 && J - 1 >= 1 && map[I - 1][J - 1] == 1 && mapCheck[I - 1][J - 1] == false) {
						S.push(pair<int, int>(I - 1, J - 1));
						mapCheck[I - 1][J - 1] = true;
						continue;
					}
					S.pop();
					if (S.empty()) total++;
				}
			}
		}
		cout << total << endl;
		for (int a = 1; a <= 100; a++) for (int b = 1; b <= 100; b++) {
			map[a][b] = 0;
			mapCheck[a][b] = false;
		}
	}
	return 0;
}