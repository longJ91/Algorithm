// 문제 : https://www.acmicpc.net/problem/2109
// 삼성 상반기 문제 비슷한 유형
/*
유명한 그리디 알고리즘 schedule with deadline
일단 일 순서대로 오름차순 정렬한 다음, 스케줄에 순서대로 넣는다
현재 스케줄이 불가능 하면 비용이 최소인 일정은 제거한다
참조 - http://codersbrunch.blogspot.kr/2016/12/2109.html
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
bool cmp(const int &a, const int &b) {
	return a > b;
}
using namespace std;
pair <int, int> cost[10000];
priority_queue<int> max_heap;
int n, ans;
int main() {
	cin >> n;
	int p, d;
	for (int i = 0; i < n; i++) {
		cin >> cost[i].second >> cost[i].first;
	}
	sort(cost, cost + n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		ans += cost[i].second;
		max_heap.push(-cost[i].second);
		if (max_heap.size() > cost[i].first) ans += max_heap.top(), max_heap.pop();
	}
	cout << ans << endl;
	return 1;
}