// 문제 : https://www.acmicpc.net/problem/14501
// 완전탐색
#include <iostream>
using namespace std;
struct work {
	int time, cost;
};
work list[16];
int result = 0;
void go(int day, int N, int tempOfMax) {
	if (list[day].time + day - 1 <= N) tempOfMax += list[day].cost;
	for (int i = day + list[day].time; i <= N ; i++){
		go(i, N, tempOfMax);
	}
	tempOfMax > result ? result = tempOfMax : 0;
}
int main() {
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> list[i].time >> list[i].cost;
	for (int i=1;i<=N;i++) go(i, N, 0);
	cout << result;

	return 1;
}