// 문제 : https://www.acmicpc.net/problem/5427
// 삼성 sw 대비
// BFS 응용
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int map[1000][1000];
int test_case, w, h;
struct SG {
	int x, y;
	int depth;
}first_position;
string str;
int main() {
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		int result = -1;
		cin >> w >> h;
		queue< pair<int, int> > fire;
		for (int i = 0; i < h; i++) {
			cin >> str;
			for (int j = 0; j < w; j++) {
				if (str[j] == '*') {
					map[i][j] = 0;
					fire.push(make_pair(i, j));
				}
				else if (str[j] == '.') map[i][j] = 1;
				else if(str[j] == '#') map[i][j] = -1;
				else if (str[j] == '@') {
					map[i][j] = 1;
					first_position.x = i;
					first_position.y = j;
					first_position.depth = 1;
				}
			}
		}
		queue< SG > set;
		set.push(first_position);
		int set_size = 1, pre_depth = 0;
		while (set_size != 0) {
			SG now = set.front();
			set.pop(); set_size--;
			if (pre_depth != now.depth) {
				//불 번지게 하기
				int fire_size = fire.size();
				for (int f = 0; f < fire_size; f++) {
					pair<int, int> now_fire = fire.front();
					fire.pop();
					int x, y;
					x = now_fire.first; y = now_fire.second;
					if (x - 1 >= 0 && map[x - 1][y] == 1) {
						map[x - 1][y] = 0;
						fire.push(make_pair(x - 1, y));
					}
					if (x + 1 < h && map[x + 1][y] == 1) {
						map[x + 1][y] = 0;
						fire.push(make_pair(x + 1, y));
					}
					if (y - 1 >= 0 && map[x][y - 1] == 1) {
						map[x][y - 1] = 0;
						fire.push(make_pair(x, y - 1));
					}
					if (y + 1 < w && map[x][y + 1] == 1) {
						map[x][y + 1] = 0;
						fire.push(make_pair(x, y + 1));
					}
				}
				pre_depth++;
			}
			//finish
			if (now.x == 0 || now.x == h - 1 || now.y == 0 || now.y == w - 1) {
				set_size = 0;
				result = now.depth;
				break;
			}
			//이동 가능한 구간으로 전진
			if (now.x - 1 >= 0 && map[now.x - 1][now.y] == 1) {
				map[now.x - 1][now.y] = 0;
				SG next;
				next.x = now.x - 1; next.y = now.y; next.depth = now.depth + 1;
				set.push(next);
				set_size++;
			}
			if (now.x + 1 < h  && map[now.x + 1][now.y] == 1) {
				map[now.x + 1][now.y] = 0;
				SG next;
				next.x = now.x + 1; next.y = now.y; next.depth = now.depth + 1;
				set.push(next);
				set_size++;
			}
			if (now.y - 1 >= 0 && map[now.x][now.y - 1] == 1) {
				map[now.x][now.y - 1] = 0;
				SG next;
				next.x = now.x; next.y = now.y - 1; next.depth = now.depth + 1;
				set.push(next);
				set_size++;
			}
			if (now.y + 1 < w  && map[now.x][now.y + 1] == 1) {
				map[now.x][now.y + 1] = 0;
				SG next;
				next.x = now.x; next.y = now.y + 1; next.depth = now.depth + 1;
				set.push(next);
				set_size++;
			}
		}
		if (result == -1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << result << "\n";
		}
	}
	return 1;
}