// ���� : https://www.acmicpc.net/problem/2109
// �Ｚ ��ݱ� ���� ����� ����
/*
������ �׸��� �˰��� schedule with deadline
�ϴ� �� ������� �������� ������ ����, �����ٿ� ������� �ִ´�
���� �������� �Ұ��� �ϸ� ����� �ּ��� ������ �����Ѵ�
���� - http://codersbrunch.blogspot.kr/2016/12/2109.html
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