// 문제 : https://www.acmicpc.net/problem/1158
// 원으로 줄이 이어지는 부분을 queue 구조를 이용해서 풀이
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	queue<int> Q;
	int N, M;
	string result;

	result = "<";

	cin >> N; cin >> M;

	for (int i = 1; i <= N; i++) Q.push(i);

	while (!Q.empty()) {
		for (int i = 1; i < M; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		Q.size() != 1 ? result += to_string(Q.front()) + ", " : result += to_string(Q.front()) + ">";
		Q.pop();
	}

	cout << result;

	return 1;
}