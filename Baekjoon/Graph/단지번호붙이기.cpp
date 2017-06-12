// ¹®Á¦ : https://www.acmicpc.net/problem/2667
//
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
int map[26][26];
bool mapCheck[26][26];
using namespace std;
int main() {
	int N;
	char enter;
	vector<int> result;
	cin >> N;
	enter = getc(stdin);
	for (int i = 1; i <= N; i++) {
		string temp;
		getline(cin, temp);
		for (int j = 1; j <= N; j++) map[i][j] = temp.at(j - 1) - '0';
	}
	stack< pair<int,int> > S;
	int total = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt = 0;
			if (map[i][j] == 1 && mapCheck[i][j] == false) {
				S.push(pair<int, int>(i, j));
				mapCheck[i][j] = true;
				cnt++;
			}
			//DFS
			while (!S.empty()) {
				int I, J;
				I = S.top().first;
				J = S.top().second;
				if (I - 1 >= 1 && I - 1 <= N && map[I - 1][J] == 1 && mapCheck[I - 1][J] == false) {
					S.push(pair<int, int>(I - 1, J));
					mapCheck[I - 1][J] = true;
					cnt++;
					continue;
				}
				if (J + 1 >= 1 && J + 1 <= N && map[I][J + 1] == 1 && mapCheck[I][J + 1] == false) {
					S.push(pair<int, int>(I, J + 1));
					mapCheck[I][J + 1] = true;
					cnt++;
					continue;
				}
				if (I + 1 >= 1 && I + 1 <= N && map[I + 1][J] == 1 && mapCheck[I + 1][J] == false) {
					S.push(pair<int, int>(I + 1, J));
					mapCheck[I + 1][J] = true;
					cnt++;
					continue;
				}
				if (J - 1 >= 1 && J - 1 <= N && map[I][J-1] == 1 && mapCheck[I][J-1] == false) {
					S.push(pair<int, int>(I, J - 1));
					mapCheck[I][J-1] = true;
					cnt++;
					continue;
				}
				S.pop();
				if (S.empty()) {
					total++;
					result.push_back(cnt);
				}
			}
		}
	}
	sort(result.begin(), result.end());
	cout << total << endl;
	int l = result.size();
	for (int i = 0; i < l; i++) cout << result.at(i) << endl;
	return 0;
}