// 문제 : https://www.acmicpc.net/problem/13901
#include <iostream>
#include <stack>
using namespace std;
int map[1000][1000];
bool check[1000][1000];
int main() {
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 0; i < k; i++){
		int br, bc;
		cin >> br >> bc;
		check[br][bc] = true;
	}
	int sR, sC;
	cin >> sR >> sC;
	int direct[4];//1 위(y - 1), 2 아래 (y + 1), 3 좌(x - 1), 4 우(x + 1)
	for (int i = 0; i < 4; i++) cin >> direct[i];
	stack<pair<int, int> > S;
	S.push(make_pair(sR, sC));
	check[sR][sC] = true;
	int directIndex = 0, count = 0;
	while (!S.empty()) {
		int x, y;
		x = S.top().first;
		y = S.top().second;
		if (count > 7) {
			cout << x << " " << y << endl;
			break;
		}
		if (direct[directIndex] == 1) {
			if (x - 1 >= 0 && check[x - 1][y] == false) {
				S.push(make_pair(x - 1, y));
				check[x - 1][y] = true;
				count = 0;
				continue;
			}
			else {
				directIndex = (directIndex + 1) % 4;
				count++;
				continue;
			}
		}else if (direct[directIndex] == 2) {
			if (x + 1 < r && check[x + 1][y] == false) {
				S.push(make_pair(x + 1, y));
				check[x + 1][y] = true;
				count = 0;
				continue;
			}else {
				directIndex = (directIndex + 1) % 4;
				count++;
				continue;
			}
		}else if (direct[directIndex] == 3) {
			if (y - 1 >= 0 && check[x][y - 1] == false) {
				S.push(make_pair(x, y - 1));
				check[x][y - 1] = true;
				count = 0;
				continue;
			}else {
				directIndex = (directIndex + 1) % 4;
				count++;
				continue;
			}
		}else if (direct[directIndex] == 4) {
			if (y + 1 < c && check[x][y + 1] == false) {
				S.push(make_pair(x, y + 1));
				check[x][y + 1] = true;
				count = 0;
				continue;
			}else {
				directIndex = (directIndex + 1) % 4;
				count++;
				continue;
			}
		}

	}
	return 0;
}