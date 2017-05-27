// ���� : https://www.acmicpc.net/problem/11650
// x,y ��ǥ�� ���� �� ����ü�� �����, �ش� ����ü Ÿ���� vector�� Ȱ���ؼ� ������ ����
// vector�� sort �Լ��� Ȱ�� (compare)
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
struct location {
	int x, y;
};
bool compare(const location &a, const location &b) {
	if (a.x < b.x) return true;
	else if (a.x == b.x) return a.y < b.y;
	else return false;
}
int main() {
	int T;
	location temp;
	vector<location> L;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp.x;
		cin >> temp.y;
		L.push_back(temp);
	}
	sort(L.begin(),L.end(),compare);
	for (vector<location>::iterator it = L.begin(); it != L.end(); ++it) cout << it->x << " " << it->y << "\n";
	//for (int i = 0; i < T; i++) cout << L.at(i).x << " " << L.at(i).y << "\n";
	return 1;
}