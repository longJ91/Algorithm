// ���� : https://www.acmicpc.net/problem/11651
// vector, sort Ȱ�� and compare ���Լ� ����
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct location {
	int x, y;
}temp;
bool compare(const location &a, const location &b) {
	if (a.y < b.y) return true;
	else if (a.y == b.y) return a.x < b.x;
	else return false;
}
int main() {
	int T;
	vector<location> Set;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp.x; cin >> temp.y;
		Set.push_back(temp);
	}
	sort(Set.begin(), Set.end(), compare);
	for (vector<location>::iterator it = Set.begin(); it != Set.end(); ++it) cout << it->x << " " << it->y << "\n";
	return 1;
}