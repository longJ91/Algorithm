#include <iostream>
#include <set>
using namespace std;
int move_a[4] = {1,1,-1,-1};
int move_b[4] = {1,-1,-1,1};
int map[20][20];
int test_case, n, result;
int MAX(const int &a, const int &b) {
	if (a > b) return a;
	return b;
}
int main() {
	cin.sync_with_stdio(false);
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		cin >> n;
		result = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		for (int a = 1; a <= n - 2; a++) {
			for (int b = 1; b <= n - 2; b++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == 0 && j == 0)continue;
						if (i == 0 && j == n - 1) continue;
						if (i == n - 1 && j == 0) continue;
						if (i == n - 1 && j == n - 1) continue;
						int flag = 1, x, y;
						x = i; y = j;
						x += a; y += a;
						if (x >= n || y >= n) continue;
						x += b; y -= b;
						if (x >= n || y < 0) continue;
						x -= a; y -= a;
						if (x < 0 || y < 0) continue;
						x -= b; y += b;
						if (x < 0 || y >= n) continue;
						x = i; y = j;
						set<int> s;
						for (int A = 1; A <= a; A++) {
							if (flag == -1)break;
							if (s.count(map[++x][++y]) != 0) {
								flag = -1;
								break;
							}
							s.insert(map[x][y]);
						}
						for (int B = 1; B <= b; B++) {
							if (flag == -1)break;
							if (s.count(map[++x][--y]) != 0) {
								flag = -1;
								break;
							}
							s.insert(map[x][y]);
						}
						for (int A = 1; A <= a; A++) {
							if (flag == -1)break;
							if (s.count(map[--x][--y]) != 0) {
								flag = -1;
								break;
							}
							s.insert(map[x][y]);
						}
						for (int B = 1; B <= b; B++) {
							if (flag == -1)break;
							if (s.count(map[--x][++y]) != 0) {
								flag = -1;
								break;
							}
							s.insert(map[x][y]);
						}
						if (flag != -1) result = MAX(result, s.size());
					}
				}
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}