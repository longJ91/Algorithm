#include "stdafx.h"
//O(N^2), set 활용해서 거울 갯수 확인
#include <iostream>
#include <set>
#include <string>
using namespace std;
int Answer;
int map[1001][1001];
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++){
			string temp;
			cin >> temp;
			for (int j = 1; j <= N; j++){
				map[i][j] = temp.at(j - 1) - '0';
			}
		}
		set< pair<int, int> > set;
		int x, y, direct;
		x = y = direct = 1;
		while (!(x < 1 || x > N || y < 1 || y > N)) {
			if (map[x][y] == 0) {
				if (direct == 1) {
					y++;
					continue;
				}
				if (direct == 2) {
					y--;
					continue;
				}
				if (direct == 3) {
					x++;
					continue;
				}
				if (direct == 4) {
					x--;
					continue;
				}
			}
			if (map[x][y] == 1) {
				set.insert(make_pair(x, y));
				if (direct == 1) {
					direct = 4;
					x--;
					continue;
				}
				if (direct == 2) {
					direct = 3;
					x++;
					continue;
				}
				if (direct == 3) {
					direct = 2;
					y--;
					continue;
				}
				if (direct == 4) {
					direct = 1;
					y++;
					continue;
				}
			}
			if (map[x][y] == 2) {
				set.insert(make_pair(x, y));
				if (direct == 1) {
					direct = 3;
					x++;
					continue;
				}
				if (direct == 2) {
					direct = 4;
					x--;
					continue;
				}
				if (direct == 3) {
					direct = 1;
					y++;
					continue;
				}
				if (direct == 4) {
					direct = 2;
					y--;
					continue;
				}
			}
		}
		Answer = set.size();
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}