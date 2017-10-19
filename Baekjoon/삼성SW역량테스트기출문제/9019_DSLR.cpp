// 문제 : https://www.acmicpc.net/problem/9019
// bfs + check 배열을 통해서 중복 제거
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int test_case, A, B;
int main() {
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		vector<string> check(10001, "");
		cin >> A >> B;
		queue<pair<int, string> > bfs;
		bfs.push(make_pair(A, ""));
		while (!bfs.empty()) {
			int len = bfs.size();
			for (int i = 0; i < len; i++) {
				int value = bfs.front().first;
				string str = bfs.front().second;
				bfs.pop();
				//D - double
				if (check[((2 * value) % 10000)] == "") {
					check[((2 * value) % 10000)] = str + "D";
					bfs.push(make_pair(((2 * value) % 10000), check[((2 * value) % 10000)]));
				}
				//S - 마이너스 1
				if (value == 0) {
					if (check[9999] == "") {
						check[9999] = str + "S";
						bfs.push(make_pair(9999, check[9999]));
					}
				}
				else{
					if (check[value - 1] == "") {
						check[value - 1] = str + "S";
						bfs.push(make_pair( value - 1, check[value - 1] ));
					}
				}
				int d1, d2, d3, d4;
				d4 = value % 10;
				d3 = (value / 10) % 10;
				d2 = (value / 100) % 10;
				d1 = (value / 1000);
				//L - 왼쪽으로 밀기
				int L_value = d1 + (d4 * 10) + (d3 * 100) + (d2 * 1000);
				if (check[L_value] == "") {
					check[L_value] = str + "L";
					bfs.push(make_pair(L_value, check[L_value]));
				}
				//R - 오른쪽으로 밀기
				int R_value = d3 + (d2 * 10) + (d1 * 100) + (d4 * 1000);
				if (check[R_value] == "") {
					check[R_value] = str + "R";
					bfs.push(make_pair(R_value, check[R_value]));
				}
			}
			if (check[B] != "") {
				break;
			}
		}
		cout << check[B] << "\n";
	}
	return 0;
}