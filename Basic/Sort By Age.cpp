// ���� : https://www.acmicpc.net/problem/10814
// vector, sort Ȱ�� and ����� ������ ������ struct ������ sort �� �� �ʿ��� compare �Լ� ����
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct information {
	int age, join;
	string name;
}I;
bool compare(const information &a, const information &b) {
	if (a.age < b.age) return true;
	else if (a.age == b.age) return a.join < b.join;
	else return false;
}
int main() {
	int T;
	vector<information> Set;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> I.age; cin >> I.name; I.join = i;
		Set.push_back(I);
	}
	sort(Set.begin(), Set.end(), compare);
	for (vector<information>::iterator it = Set.begin(); it != Set.end(); ++it) cout << it->age << " " << it->name << "\n";
	return 1;
}