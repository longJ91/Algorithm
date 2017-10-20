// 문제 : https://www.acmicpc.net/problem/1022
// 주어진 조건으로 결과 시뮬레이션
// row와 최소 1~49, colum 1~4 출력 - 줄 맞춤해야 해서 출력 할 숫자 백터에 순서대로 넣으면서 최대 길이 숫자 찾아두고 순서대로 다시 출력하기
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
//한번 오른쪽, 이전 odd만큼 위, 이전 odd +1 왼쪽, 이전 odd + 1 아래, 이전 odd + 1 오른쪽
int move_x[5] = {0, -1, 0, 1, 0};
int move_y[5] = {1, 0, -1, 0, 1};
int	r1, c1, r2, c2;
int main() {
	cin.sync_with_stdio(false);
	cin >> r1 >> c1 >> r2 >> c2;
	vector<vector<int>> s(r2 - r1 + 1);
	//초기화
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < c2 - c1 + 1; j++) s[i].push_back(0);
	}
	set<pair<int, int> > position;
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			position.insert(make_pair(i, j));
		}
	}
	int cnt = position.size();
	pair<int, int> now;
	now.first = 0; now.second = 0;
	if (position.count(make_pair(0, 0)) > 0) {
		cnt--;
		s[0 - r1][0 - c1] = 1;
	}
	int prev_odd, now_odd, value = 1;
	prev_odd = 1; now_odd = 3;
	int max = 0;
	while (cnt != 0) {
		//한번 오른쪽, 이전 odd만큼 위, 이전 odd +1 왼쪽, 이전 odd + 1 아래, 이전 odd + 1 오른쪽
		now.first += move_x[0];
		now.second += move_y[0];
		value++;
		if (position.count(make_pair(now.first, now.second)) > 0) {
			cnt--;
			s[now.first - r1][now.second - c1] = value;
			if (cnt == 0 && max == 0) max = value;
		}
		for (int m = 1; m <= prev_odd; m++) {
			now.first += move_x[1];
			now.second += move_y[1];
			value++;
			if (position.count(make_pair(now.first, now.second)) > 0) {
				cnt--;
				s[now.first - r1][now.second - c1] = value;
				if (cnt == 0 && max == 0) max = value;
			}
		}
		for (int m = 1; m <= prev_odd + 1; m++) {
			now.first += move_x[2];
			now.second += move_y[2];
			value++;
			if (position.count(make_pair(now.first, now.second)) > 0) {
				cnt--;
				s[now.first - r1][now.second - c1] = value;
				if (cnt == 0 && max == 0) max = value;
			}
		}
		for (int m = 1; m <= prev_odd + 1; m++) {
			now.first += move_x[3];
			now.second += move_y[3];
			value++;
			if (position.count(make_pair(now.first, now.second)) > 0) {
				cnt--;
				s[now.first - r1][now.second - c1] = value;
				if (cnt == 0 && max == 0) max = value;
			}
		}
		for (int m = 1; m <= prev_odd + 1; m++) {
			now.first += move_x[4];
			now.second += move_y[4];
			value++;
			if (position.count(make_pair(now.first, now.second)) > 0) {
				cnt--;
				s[now.first - r1][now.second - c1] = value;
				if (cnt == 0 && max == 0) max = value;
			}
		}
		prev_odd = now_odd;
		now_odd += 2;
	}
	string str = to_string(max);
	int len = str.size();
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			if(len == to_string(s[i - r1][j - c1]).size()) cout << s[i - r1][j - c1] << " ";
			else {
				for (int k = 1; k <= len - to_string(s[i - r1][j - c1]).size(); k++) {
					cout << " ";
				}
				cout << s[i - r1][j - c1] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}