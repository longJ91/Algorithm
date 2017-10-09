// 문제 : https://www.acmicpc.net/problem/9376
// 삼성 sw 대비
/*
죄수 1, 죄수 2, 모든 탈출구
총 3가지의 타입에서 감옥의 문을 여는 bfs 실행
출구 + 죄수 1 + 죄수 2 의 열었던 문의 cost를 모두 합한다.
3가지 타입에서 한곳에 정점으로 모였기 때문에 해당 정점 문을 3문 연것이므로 - 2 를 해준다.
모든 맵에서 정점중 가장 비용이 낮은게 답

나가는게 중요한게 아니라 탈출구 까지 문이 다 열려 있나가 중요 했음

최소비용인 cost를 bfs 돌릴때 항상 맨 앞에 넣어줌으로써 모든 맵 cost를 최소비용으로 먼저 채우게 해줌
여기서 중요한게 단순 큐가 아니라 덱을 이용해서 큐의 성질을 지닌 자료구조에서 앞 뒤에 자유롭게 넣고 삭제 가능한 자료구조를 사용해서 가능하게 했다는거
단순하게 기본 큐에서 갱신을 한다면 모든 맵을 결국 다시 갱신 하는 꼴이 되서 성능차이가 개 심 하게 난다
*/ 
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <tuple>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<vector<int>> bfs(vector<string> &a, int x, int y) {
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> d(n, vector<int>(m));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			d[i][j] = -1;
		}
	}
	deque<pair<int, int>> q;
	q.push_back(make_pair(x, y));
	d[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front(); q.pop_front();
		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (d[nx][ny] != -1) continue;
			if (a[nx][ny] == '*') continue;
			if (a[nx][ny] == '#') {
				d[nx][ny] = d[x][y] + 1;
				q.push_back(make_pair(nx, ny));
			}
			else {
				d[nx][ny] = d[x][y];
				q.push_front(make_pair(nx, ny));
			}
		}
	}
	return d;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n + 2);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] = "." + a[i] + ".";
		}
		n += 2;
		m += 2;
		for (int j = 0; j<m; j++) {
			a[0] += ".";
			a[n - 1] += ".";
		}
		vector<vector<int>> d0 = bfs(a, 0, 0);
		int x1, y1, x2, y2;
		x1 = y1 = x2 = y2 = -1;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (a[i][j] == '$') {
					if (x1 == -1) {
						x1 = i;
						y1 = j;
					}
					else {
						x2 = i;
						y2 = j;
					}
				}
			}
		}
		vector<vector<int>> d1 = bfs(a, x1, y1);
		vector<vector<int>> d2 = bfs(a, x2, y2);
		int ans = n*m;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (a[i][j] == '*') continue;
				int cur = d0[i][j] + d1[i][j] + d2[i][j];
				if (a[i][j] == '#') cur -= 2;
				if (ans > cur) ans = cur;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
*/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int	h, w, test_case;
char map[102][102];
int cost_first[102][102];
int cost_second[102][102];
pair<int, int> first_prisoner, second_prisoner;
int move_x[4] = { -1, 1, 0, 0 };
int move_y[4] = { 0, 0, 1, -1 };
int ans;
int main() {
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		ans = 2000000000;
		cin >> h >> w;
		memset(map, '.', sizeof(map));
		string str;
		int cnt_prisnoer = 0;
		vector<pair <int, int> > exit_list;
		for (int i = 1; i <= h; i++) {
			cin >> str;
			for (int j = 1; j <= w; j++) {
				map[i][j] = str[j-1];
				if (str[j-1] == '$') {
					if (cnt_prisnoer == 0) {
						first_prisoner = make_pair(i, j);
						cnt_prisnoer++;
					}
					else second_prisoner = make_pair(i, j);
				}
			}
		}
		deque< pair<int, int> > bfs;
		//죄수 1
		bfs.push_back(make_pair(first_prisoner.first, first_prisoner.second));
		int bfs_size = 1;
		memset(cost_first, -1, sizeof(cost_first));
		cost_first[first_prisoner.first][first_prisoner.second] = 0;
		while (bfs_size != 0) {
			int i, j;
			i = bfs.front().first;
			j = bfs.front().second;
			bfs.pop_front(); bfs_size--;
			for (int m = 0; m < 4; m++) {
				int cx = i + move_x[m];
				int cy = j + move_y[m];
				if (cx >= 0 && cx <= h+1 && cy >= 0 && cy <= w+1) {
					if (cost_first[cx][cy] == -1) {
						if (map[cx][cy] == '*') continue;
						if (map[cx][cy] == '#') {
							cost_first[cx][cy] = cost_first[i][j] + 1;
							bfs.push_back(make_pair(cx, cy));
							bfs_size++;
						}
						else {
							cost_first[cx][cy] = cost_first[i][j];
							bfs.push_front(make_pair(cx, cy));
							bfs_size++;
						}
					}
				}
			}
		}
		//죄수 2
		bfs.push_back(make_pair(second_prisoner.first, second_prisoner.second));
		bfs_size = 1;
		memset(cost_second, -1, sizeof(cost_second));
		cost_second[second_prisoner.first][second_prisoner.second] = 0;
		while (bfs_size != 0) {
			int i, j;
			i = bfs.front().first;
			j = bfs.front().second;
			bfs.pop_front(); bfs_size--;
			for (int m = 0; m < 4; m++) {
				int cx = i + move_x[m];
				int cy = j + move_y[m];
				if (cx >= 0 && cx <= h + 1 && cy >= 0 && cy <= w + 1) {
					if (cost_second[cx][cy] == -1) {
						if (map[cx][cy] == '*') continue;
						if (map[cx][cy] == '#') {
							cost_second[cx][cy] = cost_second[i][j] + 1;
							bfs.push_back(make_pair(cx, cy));
							bfs_size++;
						}
						else {
							cost_second[cx][cy] = cost_second[i][j];
							bfs.push_front(make_pair(cx, cy));
							bfs_size++;
						}
					}
				}
			}
		}
		//죄수 1, 죄수 2 정점
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				cost_first[i][j] += cost_second[i][j];
			}
		}
		//외곽
		bfs.push_back(make_pair(0, 0));
		bfs_size = 1;
		memset(cost_second, -1, sizeof(cost_second));
		cost_second[0][0] = 0;
		while (bfs_size != 0) {
			int i, j;
			i = bfs.front().first;
			j = bfs.front().second;
			bfs.pop_front(); bfs_size--;
			for (int m = 0; m < 4; m++) {
				int cx = i + move_x[m];
				int cy = j + move_y[m];
				if (cx >= 0 && cx <= h + 1 && cy >= 0 && cy <= w + 1) {
					if (cost_second[cx][cy] == -1) {
						if (map[cx][cy] == '*') continue;
						if (map[cx][cy] == '#') {
							cost_second[cx][cy] = cost_second[i][j] + 1;
							bfs.push_back(make_pair(cx, cy));
							bfs_size++;
						}
						else {
							cost_second[cx][cy] = cost_second[i][j];
							bfs.push_front(make_pair(cx, cy));
							bfs_size++;
						}
					}
				}
			}
		}
		//정점 찾기
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (map[i][j] == '*') continue;
				if (map[i][j] == '#') {
					int sum = cost_first[i][j] + cost_second[i][j];
					sum -= 2;
					ans = min(ans, sum);
				}
				else {
					int sum = cost_first[i][j] + cost_second[i][j];
					ans = min(ans, sum);
				}
			}
		}
		cout << ans << "\n";
	}
	return 1;
}
